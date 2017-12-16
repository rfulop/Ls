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
