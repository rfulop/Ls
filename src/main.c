/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:35:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/11 20:51:17 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <grp.h>
#include "libft.h"
#include "ft_printf.h"



int main(void)
{
	const char *test = ".";
	DIR* rep = NULL;
	struct dirent* file;
	struct stat sb;
	struct passwd *pwd;
	struct group *gr;

	char *conv;
	rep = opendir(test);
	if (!rep)
	{
		perror("Error : ");
		exit(1);
	}
	ft_printf("Le dossier a ete ouvert avec succes\n");
	while ((file = readdir(rep)))
	{
		ft_printf("File name is %s\n", file->d_name);
		stat(file->d_name, &sb);
		ft_printf("\t-node number: %ld\n", (long)sb.st_ino);
		ft_printf("\tMode: %lo (octal)\n", (unsigned long)sb.st_mode);
		conv = ft_itoa((int)sb.st_mode);
		ft_printf("\tMode: %d\n", sb.st_mode);
		ft_printf("\tLink count: %ld\n", (long)sb.st_nlink);
		ft_printf("\tOwnership: UID=%ld GID=%ld\n", (long)sb.st_uid, (long)sb.st_gid);
		pwd = getpwuid(sb.st_uid);
		ft_printf("\t%-8.8s\n", pwd->pw_name);
		gr = getgrgid(sb.st_gid);
		ft_printf("\t%-8.15s\n", gr->gr_name);
		ft_printf("\tPreferred I/O block size: %ld bytes\n", (long)sb.st_blksize);
		ft_printf("\tFile size: %lld bytes\n", (long long)sb.st_size);
		ft_printf("\tBlocks allocated: %lld\n", (long long)sb.st_blocks);
		ft_printf("\tLast status change: %s", ctime(&sb.st_ctime));
		ft_printf("\tLast file access: %s", ctime(&sb.st_atime));
		ft_printf("\tLast file modification: %s", ctime(&sb.st_mtime));
	}
	if (closedir(rep) == -1)
		exit(-1);
	ft_printf("Le dossier a ete ferme avec succes");
	return 0;
}
