/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:13:03 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:23:12 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void					ft_o(va_list ap, t_opt *opt, char c)
{
	unsigned long long int	o;

	if (opt->l || c == 'O')
		o = (unsigned long int)ft_l(ap);
	else if (opt->ll)
		o = (unsigned long long int)ft_ll(ap);
	else if (opt->h)
		o = (unsigned long long int)ft_h(ap);
	else if (opt->hh)
		o = (unsigned long long int)ft_hh(ap);
	else if (opt->j)
		o = (uintmax_t)ft_j(ap);
	else if (opt->z)
		o = (size_t)ft_z(ap);
	else
		o = va_arg(ap, unsigned int);
	if (opt->prec == -1 && !opt->sharp)
	{
		opt->res = ft_strnew(1);
		opt->res = ft_no_prec(opt, opt->res, c);
	}
	else
		opt->res = ft_print_xou(opt, o, 'o');
	opt->len += (int)ft_strlen(opt->res);
	free(opt->res);
}
