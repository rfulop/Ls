/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:56:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/05 09:51:25 by amacieje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(int n)
{
	int a;

	a = 1;
	while (n >= 10)
	{
		n = n / 10;
		++a;
	}
	return (a);
}

char			*ft_itoa(int n)
{
	int		a;
	int		sign;
	char	*res;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0)
	{
		sign++;
		n = n * -1;
	}
	a = ft_size(n);
	if (!(res = (char*)malloc(sizeof(char) * (a + sign + 1))))
		return (NULL);
	res[a + sign] = '\0';
	if (sign)
		res[0] = '-';
	while (a > 0)
	{
		res[a + sign - 1] = n % 10 + '0';
		n = n / 10;
		--a;
	}
	return (res);
}
