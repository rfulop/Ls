/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/02 18:44:14 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_spacechar(char const *s)
{
	int		a;
	size_t	b;

	a = 0;
	while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		++a;
	if ((size_t)a == ft_strlen(s))
		return (a);
	else
	{
		b = a;
		a = ft_strlen(s) - 1;
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
		{
			--a;
			++b;
		}
		return (b);
	}
}

char				*ft_strtrim(char const *s)
{
	int		a;
	int		b;
	int		len;
	char	*res;

	res = NULL;
	if (s)
	{
		if (ft_spacechar(s) == ft_strlen(s))
			return (ft_strnew(1));
		len = ft_strlen(s) - ft_spacechar(s) + 1;
		if (!(res = (char*)malloc(sizeof(char) * len)))
			return (NULL);
		a = 0;
		while (s[a] == ' ' || s[a] == '\n' || s[a] == '\t')
			++a;
		b = 0;
		len = len + a - 1;
		while (a < len)
			res[b++] = s[a++];
		res[b] = '\0';
	}
	return (res);
}
