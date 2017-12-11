/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2016/06/05 22:17:20 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int len;

	len = ft_strlen(dest) + (int)n;
	ft_strncpy(&dest[ft_strlen(dest)], src, n);
	dest[len] = '\0';
	return (dest);
}
