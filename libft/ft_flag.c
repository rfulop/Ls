/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:28:25 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:22:19 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_f_length(t_opt *opt, char *str)
{
	int a;

	a = 0;
	if (str[a] == 'z')
		opt->z = 1;
	else if (str[a] == 'j')
		opt->j = 1;
	else if (str[a] == 'l' || str[a] == 'h')
	{
		if (str[a] == 'l' && str[a + 1] == 'l')
		{
			a++;
			opt->ll = 1;
		}
		else if (str[a] == 'h' && str[a + 1] == 'h')
			opt->hh = 1;
		else if (str[a] == 'l' && !opt->ll)
			opt->l = 1;
		else if (str[a] == 'h' && !opt->hh)
			opt->h = 1;
	}
	return (a);
}

void	ft_f_option(t_opt *opt, char c)
{
	if (c == ' ')
		opt->space = 1;
	else if (c == '+')
		opt->plus = 1;
	else if (c == '-')
		opt->less = 1;
	else if (c == '#')
		opt->sharp = 1;
	else
		opt->zero = 1;
}

int		ft_f_width(t_opt *opt, char *str)
{
	int a;
	int	width;

	a = 0;
	width = 0;
	while (ft_isdigit(str[a]))
	{
		width = width * 10 + (str[a]) - 48;
		++a;
	}
	opt->width = width;
	return (--a);
}

int		ft_f_precision(t_opt *opt, char *str)
{
	int a;
	int precision;

	a = 1;
	precision = 0;
	while (ft_isdigit(str[a]))
	{
		precision = precision * 10 + (str[a]) - 48;
		++a;
	}
	if (a == 1 || precision == 0)
		precision = -1;
	opt->prec = precision;
	return (--a);
}

int		ft_flag(t_opt *opt, char *fmt)
{
	int a;

	a = 0;
	while (fmt[a])
	{
		if (fmt[a] == ' ' || fmt[a] == '+' || fmt[a] == '-' ||
			fmt[a] == '0' || fmt[a] == '#')
			ft_f_option(opt, fmt[a]);
		else if (ft_isdigit(fmt[a]))
			a += ft_f_width(opt, &fmt[a]);
		else if (fmt[a] == '.')
			a += ft_f_precision(opt, &fmt[a]);
		else if (fmt[a] == 'l' || fmt[a] == 'h' || fmt[a] == 'z' ||
				fmt[a] == 'j')
			a += ft_f_length(opt, &fmt[a]);
		else
			return (--a);
		a++;
	}
	return (a--);
}
