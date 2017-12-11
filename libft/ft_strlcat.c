/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/05 22:17:08 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(char *str, size_t size)
{
	size_t a;

	a = 0;
	while (a < size && str && str[a])
		++a;
	return (a);
}

size_t			ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t de;
	size_t sr;
	size_t len;

	de = ft_size(dest, n);
	sr = ft_strlen(src);
	len = n - de;
	dest += de;
	if (len > 0)
	{
		ft_strncpy(dest, src, len);
		dest[len - 1] = '\0';
	}
	return (de + sr);
}
