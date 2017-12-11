/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 19:19:59 by rfulop            #+#    #+#             */
/*   Updated: 2017/03/15 06:21:36 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(sizeof(char)
		* ft_strlen(s1) + len + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strncat(ret, s2, len);
		free((char*)s1);
	}
	return (ret);
}
