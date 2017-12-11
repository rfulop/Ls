/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 22:30:49 by rfulop            #+#    #+#             */
/*   Updated: 2017/02/12 22:51:55 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_oct(char *str)
{
	size_t	a;
	char	*res;

	a = 0;
	while (str[a] == '0')
		++a;
	if (a == ft_strlen(str))
		--a;
	res = ft_strdup(str + a);
	free(str);
	return (res);
}

char	*ft_conv_oct(char *nbr, char *base_to)
{
	int						a;
	char					*res;
	unsigned long long int	nb;

	nb = ft_atoi_ll(nbr);
	if (!(res = (char*)malloc(sizeof(char*) * 22 + 1)))
		return (NULL);
	res[22] = '\0';
	a = 21;
	while (a >= 0)
	{
		res[a] = base_to[nb % 8];
		nb = nb / 8;
		--a;
	}
	free(nbr);
	return (ft_check_oct(res));
}
