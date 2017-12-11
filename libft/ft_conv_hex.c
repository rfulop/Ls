/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 22:30:49 by rfulop            #+#    #+#             */
/*   Updated: 2017/01/17 18:23:44 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_hex(char *str)
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

char	*ft_conv_hex(char *nbr, char *base_to)
{
	int						a;
	char					*res;
	unsigned long long int	nb;

	nb = ft_atoi_ll(nbr);
	free(nbr);
	if (!(res = (char*)malloc(sizeof(char*) * 16 + 1)))
		return (NULL);
	res[16] = '\0';
	a = 15;
	while (a >= 0)
	{
		res[a] = base_to[nb % 16];
		nb = nb / 16;
		--a;
	}
	return (ft_check_hex(res));
}
