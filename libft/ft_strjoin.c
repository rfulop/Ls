/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/03/16 02:08:55 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		if (!(res = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(res, s1);
		ft_strcat(res, s2);
	}
	return (res);
}
