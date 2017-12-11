/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:56:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/03/16 02:22:52 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(unsigned long long int n)
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

char			*ft_itoa_ull(unsigned long long int n)
{
	int		a;
	char	*res;

	a = ft_size(n);
	if (!(res = (char *)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	res[a] = '\0';
	while (a > 0)
	{
		res[a - 1] = n % 10 + '0';
		n = n / 10;
		--a;
	}
	return (res);
}
