/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/02 18:26:53 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		a;
	char	*res;

	res = NULL;
	if (s)
	{
		if (!(res = ft_memalloc(ft_strlen(s) + 1)))
			return (NULL);
		a = 0;
		while (res && s && s[a])
		{
			res[a] = f(s[a]);
			++a;
		}
		res[a] = '\0';
	}
	return (res);
}
