/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:07:09 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:21:01 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_c_null(t_opt *opt, unsigned char a)
{
	while (opt->width - 1)
	{
		if (opt->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		opt->width--;
		opt->len += 1;
	}
	write(1, &a, 1);
	opt->len += 1;
}

int		ft_count_byt(wchar_t a)
{
	int		n;

	n = 0;
	while (a > 0)
	{
		a >>= 1;
		n++;
	}
	return (n);
}

void	ft_c_unicode(va_list ap, t_opt *opt, char c, wchar_t x)
{
	int			n;
	wchar_t		a;

	if (x != 0)
	{
		if (c == 'C' || (opt->l && c == 'c'))
			a = va_arg(ap, wchar_t);
		else
			a = (wchar_t)x;
		if (!a)
		{
			write(1, &a, 1);
			opt->len++;
		}
		else
		{
			n = ft_count_byt(a);
			ft_print_unicode(opt, a, n);
		}
	}
	else
		ft_c_null(opt, x);
}

void	ft_print_c(va_list ap, t_opt *opt, char c)
{
	unsigned char a;

	a = va_arg(ap, int);
	if (opt->width)
	{
		if (!a)
			ft_c_null(opt, a);
		else
		{
			opt->res = ft_strnew(1);
			opt->res[0] = a;
			opt->res = ft_width(opt, opt->res, c);
			write(1, opt->res, (int)ft_strlen(opt->res));
			opt->len = (int)ft_strlen(opt->res);
		}
	}
	else
	{
		write(1, &a, 1);
		opt->len += 1;
	}
}

void	ft_c(va_list ap, t_opt *opt, char c)
{
	if (c == 'C' || (opt->l && c == 'c'))
	{
		ft_c_unicode(ap, opt, c, '0');
		if (opt->tmp)
		{
			opt->res = ft_strdup(opt->tmp);
			free(opt->tmp);
		}
		if (opt->res)
		{
			write(1, opt->res, (int)ft_strlen(opt->res));
			opt->len += (int)ft_strlen(opt->res);
			free(opt->res);
		}
	}
	else
		ft_print_c(ap, opt, c);
}
