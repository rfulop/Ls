/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:22:55 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/13 14:25:12 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_itoa_base_int(int nb, int base)
{
	int size;
	int oct;

	size = 0;
	oct = 0;
	while (nb >= base)
	{
		oct += (nb % base) * ft_power(10, size);
		nb /= base;
		++size;
	}
	oct += (nb % base) * ft_power(10, size);
	return (oct);
}
