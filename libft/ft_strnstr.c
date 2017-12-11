/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/05 22:11:51 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int a;
	int	b;
	int c;

	c = 0;
	while (s1[c] && n > 0)
	{
		if (n < ft_strlen(s2))
			return (NULL);
		b = 0;
		a = c;
		while (s1[a] && s2[b] && s1[a] == s2[b])
		{
			++a;
			++b;
		}
		if (s2[b] == '\0')
			return ((char *)s1 + c);
		++c;
		--n;
	}
	return (NULL);
}
