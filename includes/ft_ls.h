/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:30:46 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 19:10:14 by rfulop           ###   ########.fr       */
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
#include <errno.h>
//#include <uuid/uuid.h>
#include <grp.h>
#include "libft.h"
#include "ft_printf.h"
#include <sys/xattr.h>
#include <sys/acl.h>


#

/*
** Errno error
*/
#define PERM_ERR 13
#define SIX_MON 15778800

#define 			 S_IFMT 0170000           /* type of file */
#define        S_IFIFO  0010000  /* named pipe (fifo) */
#define        S_IFCHR  0020000  /* character special */
#define        S_IFDIR  0040000  /* directory */
#define        S_IFBLK  0060000  /* block special */
#define        S_IFREG  0100000  /* regular */
#define        S_IFLNK  0120000  /* symbolic link */
#define        S_IFSOCK 0140000  /* socket */
#define        S_IFWHT  0160000  /* whiteout */

#define IS_DIR 1
#define IS_REG 2

#define F_DIR 4
#define F_REG 8
#define F_SYM 1

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
  int       max_links;
  int       max_user;
  int       max_gr;
  int       max_size;

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
  // uid_t      st_uid;
  // gid_t      st_gid;
  time_t     mtime;
  off_t      st_size;
  blkcnt_t  st_blocks;
  char       *perm;
  char       *name;
  char       *path;
  char      *link;
  char      *uid;
  char      *gid;
}              t_file;


char *get_path(char *path, char* file);
char 	*do_stat(struct dirent *file, struct stat *sb, char *path);
void count_total(t_lst *lst);
void check_dir(t_env *env, char *dir, t_lst *lst);
void open_dir(t_env *env, char *dir);
void get_maxs(t_env *env, t_lst *lst);

/*
** Init
*/
void 	init_env(t_env *env);

/*
** Parsing
*/
void	check_args_letter(t_env *env, char let);
int parse_args(t_env *env, char **argv);

/*
** Display
*/
void display(t_env *env, t_file *file);
void display_lst(t_env *env, t_lst *lst);

/*
** List tools
*/
void put_data(struct dirent *file, t_file *data, char *path);
t_lst *create_node(struct dirent *file, char *path);
void push_lst(t_env *env, struct dirent *file, t_lst **lst, char *path);

/*
** Sorting
*/
t_lst *sort_list(t_lst *lst, int (*cmp)(const char *, const char *));
int ft_strcmp_rev(const char *s1, const char *s2);
t_lst *sort_time(t_lst *lst);

/*
** Utils
*/
char *get_perm(int oct, int type, char c);

/*
** Free
*/
void free_lst(t_lst *lst);

/*
** Debug
*/
void debug_lst(t_lst *lst);
void debug_stat(struct dirent *file, struct stat *sb);
void debug_open(struct dirent *file);
void 	debug_env(t_env *env);


#endif
