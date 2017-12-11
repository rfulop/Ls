/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:35:46 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/30 19:26:00 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin_list;
	t_list *new_elem;

	if (!lst)
		return (NULL);
	if (!(begin_list = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	begin_list = f(lst);
	new_elem = begin_list;
	while (lst->next)
	{
		new_elem->next = f(lst->next);
		lst = lst->next;
		new_elem = new_elem->next;
	}
	return (begin_list);
}
