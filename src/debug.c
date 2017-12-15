/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/15 23:44:45 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	debug_env(t_env *env)
{
	ft_printf("long_form = %d\n", env->long_form);
	ft_printf("recurs = %d\n", env->recurs);
	ft_printf("hiden_file = %d\n", env->hiden_files);
	ft_printf("reverse_short = %d\n", env->reverse_short);
	ft_printf("time_short = %d\n", env->time_short);
	ft_printf("path = %s\n", env->path);
}

void debug_open(struct dirent *file)
{
	ft_printf("Inode number = %d\n", file->d_ino);
	// ft_printf("Offset = %d\n", file->d_off);
	ft_printf("Length of this record = %d\n", file->d_reclen);
	ft_printf("Type of file = %d\n", file->d_type);
}

void debug_stat(t_env *env, struct dirent *file, struct stat *sb)
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

void debug_lst(t_lst *lst)
{
	int i;
	t_lst *tmp;

	ft_printf("lst :\n");
	i = 0;
	tmp = lst;
	while (tmp)
	{
		ft_printf("%d: '%s'\n", i, tmp->data->name);
		tmp = tmp->next;
		++i;
	}
}
