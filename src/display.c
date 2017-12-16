/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:57:03 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void display(t_env *env, t_file *file)
{
	struct passwd *pwd;
	struct group *gr;
	char date[13] = {0};

	if (env->long_form)
	{
		pwd = getpwuid(file->st_uid);
		gr = getgrgid(file->st_gid);
		ft_strncpy(date, ctime(&file->mtime) + 4, 12);
		if (!env->hiden_files && file->name[0] == '.')
			;
		else
		{
			ft_printf("%s%5d %-8.8s%-12.16s%5d %s %s\n",
			file->perm, (int)file->st_nlink, pwd->pw_name, gr->gr_name, (int)file->st_size, date, file->name);
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
