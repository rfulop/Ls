/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/02 19:04:46 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int		a;
	char				*res;

	res = NULL;
	if (s)
	{
		a = 0;
		if (!(res = ft_memalloc(len + 1)))
			return (NULL);
		while ((size_t)a < len)
		{
			res[a] = s[start];
			++start;
			++a;
		}
		res[a] = '\0';
	}
	return (res);
}
