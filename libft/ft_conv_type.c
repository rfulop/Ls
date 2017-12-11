/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:25:12 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:21:49 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_print_nothing(t_opt *opt, char c)
{
	char	*str;

	if (!opt->prec && !opt->width)
		return (0);
	str = ft_strnew(1);
	str[0] = c;
	str[1] = '\0';
	if (opt->width || opt->prec)
	{
		str = ft_width(opt, str, c);
		write(1, str, (int)ft_strlen(str));
		opt->len += (int)ft_strlen(str);
	}
	free(str);
	return (1);
}

void	ft_percent(t_opt *opt)
{
	int a;

	a = 0;
	if (opt->width)
	{
		if (opt->less)
			write(1, "%", 1);
		while (a < opt->width - 1)
		{
			if (opt->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			a++;
		}
		if (!opt->less)
			write(1, "%", 1);
		opt->len += opt->width - 1;
	}
	else
		write(1, "%", 1);
	opt->len++;
}

int		ft_conv_type(va_list ap, t_opt *opt, char c)
{
	if (c == 'c' || c == 'C')
		ft_c(ap, opt, c);
	else if (c == 's' || c == 'S')
		ft_s(ap, opt, c);
	else if (c == 'd' || c == 'i' || c == 'D')
		ft_d(ap, opt, c);
	else if (c == 'x' || c == 'X')
		ft_x(ap, opt, c);
	else if (c == 'o' || c == 'O')
		ft_o(ap, opt, c);
	else if (c == 'u' || c == 'U')
		ft_u(ap, opt, c);
	else if (c == 'b')
		ft_b(ap, opt);
	else if (c == 'p')
		ft_p(ap, opt);
	else if (c == '%')
		ft_percent(opt);
	else
		return (ft_print_nothing(opt, c));
	return (1);
}
