/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:58:27 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_strcmp_rev(const char *s1, const char *s2)
{
	unsigned int	a;

	a = 0;
	while (s1[a] == s2[a])
	{
		if (s1[a] == '\0')
			return (0);
		++a;
	}
	return ((unsigned char)s2[a] - (unsigned char)s1[a]);
}

t_lst *sort_time(t_lst *lst)
{
	t_lst *begin;
	struct s_file *tmp;

	begin = lst;
	while (lst && lst->next)
	{
		if (lst->data->mtime < lst->next->data->mtime)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = begin;
		}
		else
			lst = lst->next;
	}
	lst = begin;
	return (lst);
}

t_lst *sort_list(t_lst *lst, int (*cmp)(const char *, const char *))
{
	t_lst *begin;
	struct s_file *tmp;

	begin = lst;
	while (lst && lst->next)
	{
		if ((cmp(lst->data->name, lst->next->data->name)) > 0)
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = begin;
		}
		else
			lst = lst->next;
	}
	lst = begin;
	return (lst);
}
