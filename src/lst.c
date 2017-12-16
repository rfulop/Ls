/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 19:31:14 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void put_data(t_env *env, struct dirent *file, t_file *data, char *path)
{
	struct stat sb;

	data->path = do_stat(env, file, &sb, path);
	data->type = file->d_type;
	data->st_nlink = sb.st_nlink;
	data->st_uid = sb.st_uid;
	data->st_gid = sb.st_gid;
	data->mtime = sb.st_mtime;
	data->st_size = sb.st_size;
	data->st_blocks = sb.st_blocks;
	data->name = ft_strdup(file->d_name);
	data->perm = ft_strdup(get_perm(ft_itoa_base_int((int)sb.st_mode, 8), file->d_type));
}

t_lst *create_node(t_env *env, struct dirent *file, char *path)
{
	t_lst *node;

	if (!(node = (t_lst*)malloc(sizeof(t_lst))))
		exit (-1);
	node->next = NULL;
	node->prev = NULL;
	if (!(node->data = (t_file*)malloc(sizeof(t_file))))
		exit (-1);
	put_data(env, file, node->data, path);
	return (node);
}

void push_lst(t_env *env, struct dirent *file, t_lst **lst, char *path)
{
	t_lst	*tmp;

	tmp = *lst;
	if (!env->hiden_files && 0[file->d_name] == '.')
		return ;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_node(env, file, path);
	}
	else
		*lst = create_node(env, file, path);
}
