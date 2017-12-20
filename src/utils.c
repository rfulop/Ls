/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:58:31 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int get_int_size(int nb)
{
	int size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size);
}

int get_max_links(t_lst *lst)
{
	int max;
	int nb_links;
	t_lst *tmp;

	max = 0;
	tmp = lst;
	while (tmp)
	{
		nb_links = get_int_size(tmp->data->st_nlink);
		if (nb_links > max)
			max = nb_links;
		tmp = tmp->next;
	}
	return (max);
}

int get_max_user(t_lst *lst)
{
	int max;
	int len_user;
	t_lst *tmp;

	max = 0;
	tmp = lst;
	while (tmp)
	{
		len_user = ft_strlen(tmp->data->uid);
		if (len_user > max)
			max = len_user;
		tmp = tmp->next;
	}
	return (max);
}

int get_max_gr(t_lst *lst)
{
	int max;
	int len_gr;
	t_lst *tmp;

	max = 0;
	tmp = lst;
	while (tmp)
	{
		len_gr = ft_strlen(tmp->data->gid);
		if (len_gr > max)
			max = len_gr;
		tmp = tmp->next;
	}
	return (max);
}

int get_max_size(t_lst *lst)
{
	int max;
	int nb_size;
	t_lst *tmp;

	max = 0;
	tmp = lst;
	while (tmp)
	{
		nb_size = get_int_size(tmp->data->st_size);
		if (nb_size > max)
			max = nb_size;
		tmp = tmp->next;
	}
	return (max);
}

void get_maxs(t_env *env, t_lst *lst)
{
	env->max_links = get_max_links(lst);
	env->max_user = get_max_user(lst);
	env->max_gr = get_max_gr(lst);
	env->max_size = get_max_size(lst);
	// ft_printf("Max links = %d\n", env->max_links);
	// ft_printf("Max len user = %d\n", env->max_user);
	// ft_printf("Max len gr = %d\n", env->max_gr);
	// ft_printf("Max size = %d\n", env->max_size);
}

char *get_perm(int oct, int type, char c)
{
	int i;
	int j;
	int  bit;
	static char perm[11] = {0};

	i = 2;
	j = 1;
	perm[0] = (type == F_DIR) ? 'd' : '-';
	if (type == F_SYM)
		perm[0] = 'l';
	bit = ((oct / ft_power(10, 4)) % 10);
	while (i >= 0)
	{
		bit = ((oct / ft_power(10, i)) % 10);
		--i;
		perm[j + 0] = bit & 4 ? 'r' : '-';
		perm[j + 1] = bit & 2 ? 'w' : '-';
		perm[j + 2] = bit & 1 ? 'x' : '-';
		j += 3;
	}
	bit = ((oct / ft_power(10, 3)) % 10);
	if (bit & 1)
		perm[9] = 't';
	perm[10] = (c ? c : ' ');
	return (perm);
}
