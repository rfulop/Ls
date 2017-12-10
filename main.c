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
	printf("Le dossier a ete ouvert avec succes\n");
	while ((file = readdir(rep)))
	{
		printf("File[ name is %s\n", file->d_name);
		stat(file->d_name, &sb);
		printf("\t-node number: %ld\n", (long)sb.st_ino);
		printf("\tMode: %lo (octal)\n", (unsigned long)sb.st_mode);
		printf("\tLink count: %ld\n", (long)sb.st_nlink);
		printf("\tOwnership: UID=%ld GID=%ld\n", (long)sb.st_uid, (long)sb.st_gid);
		pwd = getpwuid(sb.st_uid);
		printf("\t%-8.8s\n", pwd->pw_name);
		gr = getgrgid(sb.st_gid);
		printf("\t%-8.15s\n", gr->gr_name);
		printf("\tPreferred I/O block size: %ld bytes\n", (long)sb.st_blksize);
		printf("\tFile size: %lld bytes\n", (long long)sb.st_size);
		printf("\tBlocks allocated: %lld\n", (long long)sb.st_blocks);
		printf("\tLast status change: %s", ctime(&sb.st_ctime));
		printf("\tLast file access: %s", ctime(&sb.st_atime));
		printf("\tLast file modification: %s", ctime(&sb.st_mtime));
	}
	if (closedir(rep) == -1)
		exit(-1);
	printf("Le dossier a ete ferme avec succes");
	return 0;
}
