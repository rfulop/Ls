/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jz.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:25:12 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:22:52 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

uintmax_t		ft_j(va_list ap)
{
	uintmax_t	n;

	n = va_arg(ap, uintmax_t);
	return (n);
}

size_t			ft_z(va_list ap)
{
	size_t		n;

	n = va_arg(ap, size_t);
	return (n);
}
