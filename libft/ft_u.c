/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:17:33 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:25:48 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void					ft_u(va_list ap, t_opt *opt, char c)
{
	char					*str;
	unsigned long long int	u;

	if (opt->l || c == 'U')
		u = (unsigned long int)ft_l(ap);
	else if (opt->ll)
		u = ft_ll(ap);
	else if (opt->h)
		u = (unsigned long long int)ft_h(ap);
	else if (opt->hh)
		u = (unsigned long long int)ft_hh(ap);
	else if (opt->j)
		u = (uintmax_t)ft_j(ap);
	else if (opt->z)
		u = (size_t)ft_z(ap);
	else
		u = va_arg(ap, unsigned int);
	str = ft_print_xou(opt, u, 'u');
	if (!(!u && opt->prec))
		opt->len += (int)ft_strlen(str);
	free(str);
}
