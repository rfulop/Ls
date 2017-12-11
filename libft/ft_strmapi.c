/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/01 22:18:14 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		a;
	char				*res;

	res = NULL;
	if (s)
	{
		if (!(res = ft_memalloc(ft_strlen(s) + 1)))
			return (NULL);
		a = 0;
		while (res && s && s[a])
		{
			res[a] = f(a, s[a]);
			++a;
		}
		res[a] = '\0';
	}
	return (res);
}
