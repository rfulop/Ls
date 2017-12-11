/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:11:52 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:26:24 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void					ft_x(va_list ap, t_opt *opt, char c)
{
	unsigned long long int	x;

	if (opt->h)
		x = (unsigned long long int)ft_h(ap);
	else if (opt->hh)
		x = (unsigned long long int)ft_hh(ap);
	else if (opt->l)
		x = (unsigned long long int)ft_l(ap);
	else if (opt->ll)
		x = ft_ll(ap);
	else if (opt->z)
		x = (unsigned long long int)ft_z(ap);
	else if (opt->j)
		x = (unsigned long long int)ft_j(ap);
	else
		x = va_arg(ap, unsigned int);
	if (opt->prec == -1)
	{
		opt->res = ft_strnew(1);
		opt->res = ft_no_prec(opt, opt->res, c);
	}
	else
		opt->res = ft_print_xou(opt, x, c);
	opt->len += (int)ft_strlen(opt->res);
	free(opt->res);
}
