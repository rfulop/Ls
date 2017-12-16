/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:30:46 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:57:59 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
//#include <uuid/uuid.h>
#include <grp.h>
#include "libft.h"
#include "ft_printf.h"


// #define 			 S_IFMT 0170000           /* type of file */
// #define        S_IFIFO  0010000  /* named pipe (fifo) */
// #define        S_IFCHR  0020000  /* character special */
// #define        S_IFDIR  0040000  /* directory */
// #define        S_IFBLK  0060000  /* block special */
// #define        S_IFREG  0100000  /* regular */
// #define        S_IFLNK  0120000  /* symbolic link */
// #define        S_IFSOCK 0140000  /* socket */
// #define        S_IFWHT  0160000  /* whiteout */

#define IS_DIR 1
#define IS_REG 2

#define F_DIR 4
#define F_REG 8

#define ACT "."
#define BEF ".."
#define ROO "/"

typedef struct s_env
{
  int       long_form; // List in long format.
  int       recurs; // Recursively list subdirectories encountered.
  int       hiden_files; //Include directory entries whose names begin with a dot (.).
  int       reverse_short; // Reverse the order of the sort to get reverse lexicographical order or the oldest
  int       time_short; // Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.
  char      *path;

}           t_env;

typedef struct s_lst
{
  struct s_lst    *next;
  struct s_lst    *prev;
  struct s_file   *data;
}           t_lst;

typedef struct s_file
{
  int        type;
  nlink_t    st_nlink;
  uid_t      st_uid;
  gid_t      st_gid;
  time_t     mtime;
  off_t      st_size;
  blkcnt_t  st_blocks;
  char       *perm;
  char       *name;
  char       *path;
}              t_file;


char *get_path(char *path, char* file);
char 	*do_stat(t_env *env, struct dirent *file, struct stat *sb, char *path);
void count_total(t_lst *lst);
void check_dir(t_env *env, char *dir);
void open_dir(t_env *env, char *dir);

/*
** Init
*/
void 	init_env(t_env *env);

/*
** Parsing
*/
void	check_args_letter(t_env *env, char let);
int parse_args(t_env *env, char **argv, int argc);

/*
** Display
*/
void display(t_env *env, t_file *file);
void display_lst(t_env *env, t_lst *lst);

/*
** List tools
*/
void put_data(t_env *env, struct dirent *file, t_file *data, char *path);
t_lst *create_node(t_env *env, struct dirent *file, char *path);
void push_lst(t_env *env, struct dirent *file, t_lst **lst, char *path);

/*
** Sorting
*/
t_lst *sort_list(t_lst *lst, int (*cmp)(const char *, const char *));

/*
** Utils
*/
char *get_perm(int oct, int type);

/*
** Free
*/
void free_lst(t_lst *lst);

/*
** Debug
*/
void debug_lst(t_lst *lst);
void debug_stat(t_env *env, struct dirent *file, struct stat *sb);
void debug_open(struct dirent *file);
void 	debug_env(t_env *env);


#endif
