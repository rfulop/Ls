/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:28:25 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/20 18:50:42 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_wildcard(va_list ap, t_opt *opt)
{
	int wild;

	wild = va_arg(ap, int);
	opt->width = wild;
	return (0);
}
