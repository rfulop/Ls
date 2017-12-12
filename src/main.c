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

char *get_perm(int oct)
{
	int i;
	int j;
	int  bit;
	static char perm[12] = {0};

	i = 2;
	j = 0;
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

int get_oct(int nb)
{
	int size;
	int oct;

	size = 0;
	oct = 0;
	while (nb >= 8)
	{
		oct += (nb % 8) * ft_power(10, size);
		nb /= 8;
		++size;
	}
	oct += (nb % 8) * ft_power(10, size);
	return (oct);
}

void display(struct stat *sb, char *perm, struct passwd *pwd, struct group *gr, char *file)
{
	char date[13] = {0};

	ft_strncpy(date, ctime(&sb->st_atime) + 4, 12);
	// ft_printf("date = %s\n", date);
	ft_printf("%s%5d %-8.8s%8.15s%7d %s %s\n",
	perm, sb->st_nlink, pwd->pw_name, gr->gr_name, sb->st_size, date, file);
	// ft_printf("\tsize = %d\n", ((long long)sb->st_size * 1000) / 100000);

	// sb->st_atime[ft_strlen((char*)sb->st_atime) - 4] = '\0';
	// ft_printf("%.40s\n", ctime(&sb->st_atime));
}

int main(void)
{
	const char *test = ".";
	DIR* rep = NULL;
	struct dirent* file;
	struct stat sb;
	struct passwd *pwd;
	struct group *gr;

	rep = opendir(test);
	if (!rep)
	{
		perror("Error : ");
		exit(1);
	}
	// ft_printf("Le dossier a ete ouvert avec succes\n");
	int oct;
	while ((file = readdir(rep)))
	{
		// ft_printf("File name is %s\n", file->d_name);
		stat(file->d_name, &sb);
		// ft_printf("\t-node number: %ld\n", (long)sb.st_ino);
		// ft_printf("\tMode: %lo (octal)\n", (unsigned long)sb.st_mode);
		oct = get_oct((int)sb.st_mode);
		char *perm = get_perm(oct);
		// ft_printf("\tperm = %d -> %s\n", oct, perm);
		// ft_printf("\tLink count: %ld\n", (long)sb.st_nlink);
		// ft_printf("\tOwnership: UID=%ld GID=%ld\n", (long)sb.st_uid, (long)sb.st_gid);
		pwd = getpwuid(sb.st_uid);
		// ft_printf("\t%-8.8s\n", pwd->pw_name);
		gr = getgrgid(sb.st_gid);
		// ft_printf("\t%-8.15s\n", gr->gr_name);
		// ft_printf("\tPreferred I/O block size: %ld bytes\n", (long)sb.st_blksize);
		// ft_printf("\tFile size: %lld bytes\n", (long long)sb.st_size);
		// ft_printf("\tFile size: %d bytes\n", (int)sb.st_size);
		// ft_printf("\tBlocks allocated: %lld\n", (long long)sb.st_blocks);
		// ft_printf("\tLast status change: %s", ctime(&sb.st_ctime));
		// ft_printf("\tLast file access: %s", ctime(&sb.st_atime));
		// ft_printf("\tLast file modification: %s", ctime(&sb.st_mtime));
		display(&sb, perm, pwd, gr, file->d_name);
	}
	if (closedir(rep) == -1)
		exit(-1);
	// ft_printf("Le dossier a ete ferme avec succes");
	return 0;
}
