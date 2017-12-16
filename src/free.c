/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:56:40 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void free_lst(t_lst *lst)
{
	t_lst *tmp;
	t_lst *tmp2;

	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_memdel((void*)&tmp->data->name);
		ft_memdel((void*)&tmp->data->perm);
		ft_memdel((void*)&tmp->data->path);
		ft_memdel((void*)&tmp->data);
		ft_memdel((void*)&tmp);
		tmp = tmp2;
	}
}
