/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:35:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/10 22:39:20 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *get_perm(int oct)
{
	int i;
	int j;
	int  bit;
	static char perm[13] = {0};

	i = 2;
	j = 0;
	bit = ((oct / ft_power(10, 4)) % 10);
	while (i >= 0)
	{
		bit = ((oct / ft_power(10, i)) % 10);
		--i;
		perm[j + 0] = bit & 4 ? 'r' : '-';
		perm[j + 1] = bit & 2 ? 'w' : '-';
		perm[j + 2] = bit & 1 ? 'x' : '-';
		j += 3;
	}
	// ft_printf("oct = %d perm = %s\n", oct, perm);
	return (perm);
}

void display(struct stat *sb, char *perm, char *file)
{
	struct passwd *pwd;
	struct group *gr;
	char date[13] = {0};

	pwd = getpwuid(sb->st_uid);
	// ft_printf("\t%-8.8s\n", pwd->pw_name);
	gr = getgrgid(sb->st_gid);
	// ft_printf("\t%-8.15s\n", gr->gr_name);
	ft_strncpy(date, ctime(&sb->st_atime) + 4, 12);
	// ft_printf("date = %s\n", date);
	ft_printf("%s%5d %-8.8s%8.15s%7d %s %s\n",
	perm, sb->st_nlink, pwd->pw_name, gr->gr_name, sb->st_size, date, file);
	// ft_printf("\tsize = %d\n", ((long long)sb->st_size * 1000) / 100000);
	// sb->st_atime[ft_strlen((char*)sb->st_atime) - 4] = '\0';
	// ft_printf("%.40s\n", ctime(&sb->st_atime));
}


void 	print_env(t_env *env)
{
	ft_printf("long_form = %d\n", env->long_form);
	ft_printf("recurs = %d\n", env->recurs);
	ft_printf("hiden_file = %d\n", env->hiden_files);
	ft_printf("reverse_short = %d\n", env->reverse_short);
	ft_printf("time_short = %d\n", env->time_short);
	ft_printf("path = %s\n", env->path);
}

void 	init_env(t_env *env)
{
	env->long_form = 0;
	env->recurs = 0;
	env->hiden_files = 0;
	env->reverse_short = 0;
	env->time_short = 0;
	env->path = NULL;
}

void	check_args_letter(t_env *env, char let)
{
	if (let == 'l')
		env->long_form = 1;
	else if (let == 'R')
		env->recurs = 1;
	else if (let == 'a')
		env->hiden_files = 1;
	else if (let == 'r')
		env->reverse_short = 1;
	else if (let == 't')
		env->time_short = 1;
	else if (let == 'h')
		ft_printf("Print help");
	else
	{
		ft_printf("Invalid argument\n");
		ft_printf("Print help");
		exit(EXIT_FAILURE);
	}
}

void parse_args(t_env *env, char **argv, int argc)
{
	int a;
	int b;

	a = 2;
	while (argv[a] && *argv[a] == '-')
	{
		b = 1;
		while (argv[a][b])
		{
			check_args_letter(env, argv[a][b]);
			++b;
		}
		if (b == 1)
		{
			ft_printf("Invalid argument\n");
			// print_help();
			exit(EXIT_FAILURE);
		}
		++a;
	}
}

void display_stat(struct dirent *file, struct stat *sb)
{
	// ft_printf("%d\n", file->d_type);
	ft_printf("\nFile name is %s\n", file->d_name);
	ft_printf("\t-node number: %ld\n", (long)sb->st_ino);
	ft_printf("\tMode: %lo (octal)\n", (unsigned long)sb->st_mode);
	ft_printf("\tLink count: %ld\n", (long)sb->st_nlink);
	ft_printf("\tOwnership: UID=%ld GID=%ld\n", (long)sb->st_uid, (long)sb->st_gid);
	ft_printf("\tPreferred I/O block size: %ld bytes\n", (long)sb->st_blksize);
	ft_printf("\tFile size: %lld bytes\n", (long long)sb->st_size);
	ft_printf("\tFile size: %d bytes\n", (int)sb->st_size);
	ft_printf("\tBlocks allocated: %lld\n", (long long)sb->st_blocks);
	ft_printf("\tLast status change: %s", ctime(&sb->st_ctime));
	ft_printf("\tLast file access: %s", ctime(&sb->st_atime));
	ft_printf("\tLast file modification: %s", ctime(&sb->st_mtime));
}

void put_data(struct dirent *file, t_file *data, int type)
{
	struct stat sb;

	// ft_printf("%d\n", file->d_type);
	stat(file->d_name, &sb);
	// display_stat(file, &sb);
	data->perm = get_perm(ft_itoa_base_int((int)sb.st_mode, 8));
	data->type = type;
	display(&sb, data->perm, file->d_name);
}

void push_lst(struct dirent *file, t_lst *lst, int type)
{
	t_lst	*previous;
	t_lst	*tmp;
	t_list	*elem;

	previous = NULL;
	tmp = lst;
	while (tmp)
	{
		previous = tmp;
		tmp = tmp->next;
	}
	if (!(tmp = (t_lst*)malloc(sizeof(t_lst))))
		exit (-1);
	tmp->next = NULL;
	tmp->prev = previous;
	if (!(tmp->data = (t_file*)malloc(sizeof(t_file))))
		exit (-1);
	put_data(file, tmp->data, type);
}

int main(int argc, char **argv)
{
	t_env env;
	DIR* rep = NULL;
	struct dirent* file = NULL;
	// struct stat sb;
	t_lst *lst;

	if (argc < 2)
		exit(-1);
	init_env(&env);
	lst = NULL;
	env.path = ft_strdup(argv[1]);
	rep = opendir(env.path);
	parse_args(&env, argv, argc);
	// print_env(&env);
	if (!rep)
	{
		perror("Error : ");
		exit(1);
	}
	while ((file = readdir(rep)))
	{
		push_lst(file, lst, 1);
		// ft_printf("%d\n", file->d_type);
		// ft_printf("File name is %s\n", file->d_name);
		// stat(file->d_name, &sb);
		// oct = ft_itoa_base_int((int)sb.st_mode, 8);
		// char *perm = get_perm(oct);
		// ft_printf("\tperm = %d -> %s\n", oct, perm);
		// display_stat(file, &sb);
		// display(&sb, perm, file->d_name);
		// file = NULL;
	}
	if (closedir(rep) == -1)
		exit(-1);
	// ft_printf("Le dossier a ete ferme avec succes");
	return 0;
}
