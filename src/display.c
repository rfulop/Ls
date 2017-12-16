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

	if (env->long_form)
	{
		pwd = getpwuid(file->st_uid);
		gr = getgrgid(file->st_gid);
		if (!pwd || !gr)
		perror("Error :");
		ft_strncpy(date, ctime(&file->mtime) + 4, 12);
		if (!env->hiden_files && file->name[0] == '.')
			;
		else
		{
		// ft_printf("\nDisplay File name = %s\n", file->name);
		// 	ft_printf("perm = %s\n", file->perm);
		// 	ft_printf("st nlink = %d\n", file->st_nlink);
		// 	if (!pwd || !pwd->pw_name)
		// 		ft_printf("pw_name = 1000\n");
		// 	else
		// 		ft_printf("pw_name = %s\n", pwd->pw_name);
		// 	if (!gr || !gr->gr_name)
		// 		ft_printf("gr_name = 1000\n");
		// 	else
		// 		ft_printf("gr_name = %s\n", gr->gr_name);
		// 	ft_printf("st_size = %d\n", file->st_size);
		// 	ft_printf("date = %s\n", date);
		// 	ft_printf("file name = %s\n", file->name);
			if (!pwd || !gr || !pwd->pw_name || !gr->gr_name)
				ft_printf("pass\n");
			else
			{
				ft_printf("%s%5d %-8.8s%-12.16s%5d %s %s\n",
				file->perm, file->st_nlink, pwd->pw_name, gr->gr_name, file->st_size, date, file->name);
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
