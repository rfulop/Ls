/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:56:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/03/16 02:29:02 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_itoa_count_size(t_ulong n, int len)
{
	int a;

	a = 1;
	while (n >= (t_ulong)len)
	{
		n = n / len;
		++a;
	}
	return (a);
}

char		*ft_itoa_base(t_ulong n, char *base_from)
{
	int		a;
	int		len;
	char	*res;

	res = NULL;
	len = ft_strlen(base_from);
	if (n == 0 || base_from == 0)
		return (ft_strdup("0"));
	a = ft_itoa_count_size(n, len);
	if (!(res = malloc(sizeof(char) * (a + 1))))
		return (NULL);
	res[a] = '\0';
	ft_strclr(res);
	while (a > 0)
	{
		res[a - 1] = base_from[n % len];
		n = n / len;
		--a;
	}
	return (res);
}
