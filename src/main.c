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

void open_dir(t_env *env, char *dir);

char *get_perm(int oct, int type)
{
	int i;
	int j;
	int  bit;
	static char perm[13] = {0};

	i = 2;
	j = 1;
	perm[0] = type == 4 ? 'd' : '-';
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
	return (perm);
}

void display(t_env *env, struct stat *sb, char *perm, char *file)
{
	struct passwd *pwd;
	struct group *gr;
	char date[13] = {0};

	pwd = getpwuid(sb->st_uid);
	// ft_printf("\t%-8.8s\n", pwd->pw_name);
	gr = getgrgid(sb->st_gid);
	// ft_printf("\t%-8.15s\n", gr->gr_name);
	ft_strncpy(date, ctime(&sb->st_mtime) + 4, 12);
	// ft_printf("date = %s\n", date);
	// ft_printf("%s%5d %-8.8s%-12.16s%5d\n",
	// perm, sb->st_nlink, pwd->pw_name, gr->gr_name, sb->st_size);
	ft_printf("%s%5d %-8.8s%-12.16s%5d %s %s\n",
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
	env->total = 0;
	env->path = NULL;
	env->curr_path = NULL;
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

void display_open(struct dirent *file)
{
	ft_printf("Inode number = %d\n", file->d_ino);
	// ft_printf("Offset = %d\n", file->d_off);
	ft_printf("Length of this record = %d\n", file->d_reclen);
	ft_printf("Type of file = %d\n", file->d_type);
}

void display_stat(t_env *env, struct dirent *file, struct stat *sb)
{
	ft_printf("\n");
	// ft_printf("\nFile type = %d\n", file->d_type);
	if (file->d_type == 8)
		ft_printf("\tFile is regular\n");
	else
		ft_printf("\tFile is a directory\n");
	ft_printf("\tFile name is %s\n", file->d_name);
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

int 	do_stat(t_env *env, struct dirent *file, struct stat *sb)
{
	int statret;
	char *path;
	char *tmp;

	tmp = env->curr_path;
	if (0[tmp] == '.')
		path = file->d_name;
	else
	{
		path = ft_strjoin(tmp, "/");
		path = ft_strjoin(path, file->d_name);
	}
	statret = stat(path, sb);
	return (statret);
}

void put_data(t_env *env, struct dirent *file, t_file *data)
{
	struct stat sb;

	do_stat(env, file, &sb);
	// display_stat(env, file, &sb);
	data->perm = get_perm(ft_itoa_base_int((int)sb.st_mode, 8), file->d_type);
	if (file->d_type == F_DIR && ft_strcmp(ACT, file->d_name) && ft_strcmp(BEF, file->d_name))
	{
		open_dir(env, file->d_name);
		// ft_printf("%s is a dir\n", file->d_name);
	}
	display(env, &sb, data->perm, file->d_name);
	env->total += sb.st_blocks;
}

void push_lst(t_env *env, struct dirent *file, t_lst *lst)
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
	put_data(env, file, tmp->data);
}


void open_dir(t_env *env, char *dir)
{
	ft_printf("1 dir = %s\n", dir);
	t_lst *lst;
	DIR *rep = NULL;
	struct dirent* file = NULL;

	rep = opendir(dir);
	while ((file = readdir(rep)))
		push_lst(env, file, lst);

	if (closedir(rep) == -1)
		exit(-1);
	ft_printf("1\n");
}

void display_lst(t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("tmp->name = %s\n", tmp->data->name);
		tmp = tmp->next;
	}
}

int count_total(t_env *env)
{
	int total;
	struct stat sb;
	struct dirent *file;
	DIR *rep;

	total = 0;
	rep = opendir(env->path);
	while ((file = readdir(rep)))
	{
		// display_open(file);
		do_stat(env, file, &sb);
		total += sb.st_blocks;
	}
	closedir(rep);
	ft_printf("Total %d\n", total);
	return (total);
}

int main(int argc, char **argv)
{
	t_env env;
	DIR* rep = NULL;
	// struct stat sb;

	init_env(&env);
	if (argc < 2)
		env.path = ".";
	else
		env.path = ft_strdup(argv[1]);
	env.curr_path = ft_strdup(env.path);
	parse_args(&env, argv, argc);
	// print_env(&env);
	count_total(&env);
	open_dir(&env, env.path);
	// display_lst(lst);
	return 0;
}
