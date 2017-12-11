/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/03/16 02:20:08 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *s1, char *s2, int n)
{
	char	*res;
	char	*tmp;

	res = NULL;
	if (s1 && s2)
	{
		if (n == 3 || ((((s2[0] == '-') && s2[1]) || ((s2[0] == '+') &&
			s2[1])) && s1[0] != ' '))
		{
			tmp = (char*)s2;
			s2++;
			n = 3;
		}
		if (!(res = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(res, s1);
		ft_strcat(res, s2);
	}
	if (n == 1)
		free(s1);
	else if (n == 2)
		free(s2);
	else
		free((char*)tmp);
	return (res);
}
