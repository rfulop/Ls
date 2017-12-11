/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:26:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:23:24 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_p(va_list ap, t_opt *opt)
{
	int			a;
	t_ulong		n;
	char		*str;

	n = va_arg(ap, t_ulong);
	str = ft_itoa_base(n, HEX2);
	if (opt->prec)
		str = ft_prec(opt, str, 'p');
	if (opt->width)
		str = ft_width(opt, str, 'p');
	a = 0;
	while (str[a] && str[a] == ' ')
	{
		write(1, " ", 1);
		++a;
	}
	write(1, "0x", 2);
	if (!ft_strcmp(str, "0") && opt->prec == -1)
		opt->len += 2;
	else
	{
		write(1, str + a, (int)ft_strlen(str + a));
		opt->len += (int)ft_strlen(str) + 2;
	}
	free(str);
}
