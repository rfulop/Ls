/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:25:12 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:21:34 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

long int		ft_ld(va_list ap)
{
	long int n;

	n = va_arg(ap, long int);
	if (n < LONG_MIN || n > LONG_MAX)
		n = n < 0 ? LONG_MIN : LONG_MAX;
	return (n);
}

long long int	ft_lld(va_list ap)
{
	long long int n;

	n = va_arg(ap, long long int);
	if (n < LLONG_MIN || n > LLONG_MAX)
		n = n < 0 ? LLONG_MIN : LLONG_MAX;
	return (n);
}

signed char		ft_hhd(va_list ap)
{
	int n;

	n = va_arg(ap, int);
	n = (char)n;
	if (n < SCHAR_MIN || n > SCHAR_MAX)
		n = n < 0 ? SCHAR_MIN : SCHAR_MAX;
	return ((signed char)n);
}

short			ft_hd(va_list ap)
{
	short		n;

	n = va_arg(ap, int);
	if (n < SHRT_MIN || n > SHRT_MAX)
		n = n < 0 ? SHRT_MIN : SHRT_MAX;
	return ((short)n);
}
