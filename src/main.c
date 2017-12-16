/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:35:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 19:31:36 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *get_path(char *dir, char* file)
{
	char *path;
	char *tmp;
	char *tmp2;

	tmp = dir;
	if (!(ft_strcmp(tmp, ACT)))
		path = ft_strdup(file);
	else if (!(ft_strcmp(tmp, ROO)))
		path = ft_strjoin("/", file);
	else
	{
		tmp2 = ft_strjoin(tmp, "/");
		path = ft_strjoin(tmp2, file);
		ft_memdel((void*)&tmp2);
	}
	return (path);
}

char 	*do_stat(t_env *env, struct dirent *file, struct stat *sb, char *dir)
{
	int statret;
	char *path;

	path = get_path(dir, file->d_name);
	statret = stat(path, sb);
	return (path);
}

void count_total(t_lst *lst)
{
	int total;
	t_lst *tmp;

	total = 0;
	tmp = lst;
	while (tmp)
	{
		total += tmp->data->st_blocks;
		tmp = tmp->next;
	}
	ft_printf("total %d\n", total);
}

void check_dir(t_env *env, char *dir, t_lst *lst)
{
	char *path;
	t_lst *tmp;

	tmp = lst;
	while (lst)
	{
	 if (lst->data->type == F_DIR && ft_strcmp(ACT, lst->data->name) && ft_strcmp(BEF, lst->data->name))
	 {
		 		path = get_path(dir, lst->data->name);
		 		open_dir(env, path);
		 		ft_memdel((void*)&path);
	 }
		lst = lst->next;
	}
}

void open_dir(t_env *env, char *dir)
{
	char *tmp;
	t_lst *lst;
	DIR *rep = NULL;
	struct dirent* file = NULL;

	// ft_printf("opendir - Dir = %s\n", dir);
	if (!(rep = opendir(dir)))
		exit (-1);
	lst = NULL;
	while ((file = readdir(rep)))
		push_lst(env, file, &lst, dir);
	if (env->long_form)
	{
		if (!(ft_strcmp(env->path, dir)))
			;
		else
			ft_printf("\n%s:\n", dir);
		count_total(lst);
	}
	lst = sort_list(lst, ft_strcmp);
	display_lst(env, lst);
	if (env->recurs)
		check_dir(env, dir, lst);
	if (closedir(rep) == -1)
		exit(-1);
	free_lst(lst);
}

int main(int argc, char **argv)
{
	int i;
	t_env env;
	DIR* rep = NULL;
	char *tmp;

	init_env(&env);
	i = parse_args(&env, argv, argc);
	if (i == argc)
		env.path = ft_strdup(".");
	else
		env.path = ft_strdup(argv[i]);
	open_dir(&env, env.path);
	ft_memdel((void*)&env.path);
	return 0;
}
