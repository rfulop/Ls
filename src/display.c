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

char *get_date(time_t mtime)
{
	char *date;
	char *ret;

	ret = ft_strnew(13);
	date = ctime(&mtime);
	time_t now = time(NULL);
	if ((now - mtime) < SIX_MON)
		ft_strncpy(ret, date + 4, 12);
	else
	{
		ft_strncpy(ret, date + 4, 7);
		ft_strncat(ret, date + 19, 5);
	}
	return (ret);
}

void display(t_env *env, t_file *file)
{
	char *date;

	if (env->long_form)
	{
		date = get_date(file->mtime);
		if (!env->hiden_files && file->name[0] == '.')
			;
		else
		{
			if (!file->uid || !file->gid)
				ft_printf("pass\n");
			else
			{

				ft_printf("%s ", file->perm);
				ft_printf("%*d ", env->max_links, file->st_nlink);
				ft_printf("%-*s  ", env->max_user, file->uid);
				ft_printf("%-*s  ", env->max_gr, file->gid);
				ft_printf("%*d ", env->max_size, file->st_size);
				ft_printf("%s %s", date, file->name);
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
	ft_memdel((void*)&date);
}

void display_lst(t_env *env, t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	get_maxs(env, tmp);
	while (tmp)
	{
		display(env, tmp->data);
		tmp = tmp->next;
	}
}
