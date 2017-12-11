/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:10:00 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:25:22 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_concat_unicode_s(va_list ap, t_opt *opt, wchar_t *str, int len)
{
	int		a;

	a = 0;
	opt->res = NULL;
	while (str[a] && len)
	{
		ft_c_unicode(ap, opt, 'S', str[a]);
		if (!opt->unicode)
			opt->unicode = (int)ft_strlen(opt->tmp);
		else if (opt->prec >= (opt->unicode + (int)ft_strlen(opt->tmp)))
			opt->unicode += (int)ft_strlen(opt->tmp);
		if (a == 0)
			opt->res = ft_strdup(opt->tmp);
		else
			opt->res = ft_strnjoin(opt->res, opt->tmp,
			(int)ft_strlen(opt->tmp));
		++a;
		free(opt->tmp);
		--len;
	}
}

void	ft_s_unicode(va_list ap, t_opt *opt)
{
	int		len;
	wchar_t *str;

	str = va_arg(ap, wchar_t *);
	if (!str)
	{
		write(1, "(null)", 6);
		opt->len += 6;
	}
	else
	{
		len = 0;
		while (str[len])
			++len;
		ft_concat_unicode_s(ap, opt, str, len);
		if (opt->prec > 0)
			opt->prec = opt->unicode;
	}
}

void	ft_print_s(va_list ap, t_opt *opt)
{
	char		*str;
	char		*res;

	str = va_arg(ap, char *);
	if (!str && !opt->width)
	{
		write(1, "(null)", 6);
		opt->len += 6;
	}
	else
	{
		if (!str)
			res = ft_strnew(1);
		else
			res = ft_strdup(str);
		if (opt->prec)
			res = ft_prec_s(opt, res);
		if (opt->width)
			res = ft_width(opt, res, 's');
		write(1, res, (int)ft_strlen(res));
		opt->len += (int)ft_strlen(res);
		free(res);
	}
}

void	ft_s(va_list ap, t_opt *opt, char c)
{
	if (c == 'S' || (opt->l && c == 's'))
	{
		ft_s_unicode(ap, opt);
		if (opt->res)
		{
			if ((opt->prec))
				opt->res = ft_prec_s(opt, opt->res);
			if (opt->width)
				opt->res = ft_width(opt, opt->res, 'S');
			write(1, opt->res, (int)ft_strlen(opt->res));
			opt->len += (int)ft_strlen(opt->res);
		}
		free(opt->res);
	}
	else
		ft_print_s(ap, opt);
}
