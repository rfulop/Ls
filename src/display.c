/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 19:29:45 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display(t_env *env, t_file *file)
{
	struct passwd *pwd;
	struct group *gr;
	char date[13] = {0};
	char *test;

	// char *list;
	// ft_printf("path = %s\n", file->path);
	// size_t test = listxattr(file->path, list, 0, 0);
	// ft_printf("test = %d\n", test);
	if (env->long_form)
	{
		pwd = getpwuid(file->st_uid);
		gr = getgrgid(file->st_gid);
		if (!pwd || !gr)
		perror("Error :");
		test = ctime(&file->mtime);
		// ft_printf("%s -> %s\n", file->name, test);
		ft_strncpy(date, ctime(&file->mtime) + 4, 12);
		if (!env->hiden_files && file->name[0] == '.')
			;
		else
		{
			if (!pwd || !gr || !pwd->pw_name || !gr->gr_name)
				ft_printf("pass\n");
			else
			{
				// ft_printf("%s%5d %-8.8s%-12.16s%5d %s %s",
				ft_printf("%-12.12s%2d %-8.8s%-11.11s%7d %-12.12s %s",
				file->perm, file->st_nlink, pwd->pw_name, gr->gr_name,
				file->st_size, date, file->name);
				if (file->link)
					ft_printf(" -> %s\n", file->link);
				else
					ft_printf("\n");
			}
		}
	}
	else
	{
		if (!env->hiden_files && file->name[0] == '.')
			;
		else
			ft_printf("%s\n", file->name);
	}
}

void display_lst(t_env *env, t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	while (tmp)
	{
		display(env, tmp->data);
		tmp = tmp->next;
	}
}
