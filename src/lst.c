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

// char *put_name(char *name, char *path)
char *put_symb(char *path)
{
	char *ret;
	char link[100];

	ret = NULL;
	ft_bzero(link, 100);
	// ret = ft_strdup(name);
	readlink(path, link, 100);
	if (link[0])
		ret = ft_strdup(link);
	return (ret);
}
// if acl -> t
// if permissions fields -> @
char get_spec_c(t_file *data)
{
	char c;
	size_t xattr;
	acl_t acl;
	// char *tmp_path;

	c = 0;
	// tmp_path = NULL;
	// ft_printf("\nreal path = %s\n", data->path);
	// xattr = listxattr(data->path, NULL, 0, 0);
	acl = acl_get_file(data->path, ACL_TYPE_EXTENDED);
	// if (data->link)
	// {
		// tmp_path = get_path("", data->link);
		// ft_printf("HAS LINK %s, tmp path = %s\n", data->link, tmp_path);
		// xattr = listxattr(tmp_path, NULL, 0, XATTR_NOFOLLOW);

		// perror(tmp_path);
	// }
	// els
		xattr = listxattr(data->path, NULL, 0, XATTR_NOFOLLOW);
	// ft_printf("xattr = %d\n", xattr);
	if (acl)
	{
		// ft_printf("data->path = %s has acl = %d\n", data->path, (int)acl);
		c = '+';
	}
	if (xattr && (int)xattr != -1)
	{
		// ft_printf("File %s has %d xattrn", data->name, xattr);
		c = '@';
	}
	if (data->link)
	{
		// c = '@';
		data->type = F_SYM;
	}
	acl_free((void *)acl);
	return (c);
}

void put_data(struct dirent *file, t_file *data, char *path)
{
	char c;
	struct stat sb;
	struct passwd *pwd;
	struct group *gr;

	data->path = do_stat(file, &sb, path);
	data->name = ft_strdup(file->d_name);
	data->link = put_symb(data->path);
	if (data->link)
		lstat(data->path, &sb);
	data->type = file->d_type;
	data->st_nlink = sb.st_nlink;
	gr = getgrgid(sb.st_gid);
	pwd = getpwuid(sb.st_uid);
	data->uid = pwd->pw_name;
	data->gid = gr->gr_name;
	// data->st_uid = sb.st_uid;
	// data->st_gid = sb.st_gid;
	data->mtime = sb.st_mtime;
	data->st_size = sb.st_size;
	data->st_blocks = sb.st_blocks;
	c = get_spec_c(data);
	data->perm = ft_strdup(get_perm(ft_itoa_base_int((int)sb.st_mode, 8), data->type, c));
}

t_lst *create_node(struct dirent *file, char *path)
{
	t_lst *node;

	if (!(node = (t_lst*)malloc(sizeof(t_lst))))
		exit (-1);
	node->next = NULL;
	node->prev = NULL;
	if (!(node->data = (t_file*)malloc(sizeof(t_file))))
		exit (-1);
	put_data(file, node->data, path);
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
		tmp->next = create_node(file, path);
	}
	else
		*lst = create_node(file, path);
}
