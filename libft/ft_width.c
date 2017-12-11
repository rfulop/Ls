/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:09:02 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:26:12 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_less(t_opt *opt, char *str, char c)
{
	int a;
	int len;

	a = 0;
	len = (int)ft_strlen(str);
	if (opt->sharp && ((c == 'x') || (c == 'X')))
	{
		a += 2;
		str = ft_put_0x(str, c);
	}
	if (c == 'p')
		a += 2;
	while (len + a < opt->width)
	{
		str = ft_stradd(str, " ", 1);
		++a;
	}
	return (str);
}

char	*ft_add_width(t_opt *opt, char *str, char c, int a)
{
	int len;

	len = (int)ft_strlen(str);
	if ((c != 'u' && (opt->sharp) && opt->zero) || (c == 'p'))
		a += 2;
	while (len + a < opt->width)
	{
		if (opt->zero && opt->prec && len == opt->prec)
			str = ft_stradd(" ", str, 2);
		else if ((opt->zero) || (opt->zero && c == 's'))
		{
			if (opt->space)
				str = ft_stradd(str, "0", 1);
			else
				str = ft_stradd("0", str, 2);
		}
		else
			str = ft_stradd(" ", str, 2);
		if (opt->zero && (opt->isneg))
			str = ft_stradd("-", str, 2);
		if (opt->zero && (opt->plus && !opt->isneg))
			str = ft_stradd("+", str, 2);
		++a;
	}
	return (str);
}

char	*ft_width(t_opt *opt, char *str, char c)
{
	int a;

	a = 0;
	if (str[0] == '-' && c != 's' && c != 'c')
		opt->isneg++;
	if (opt->less)
		str = ft_less(opt, str, c);
	else
		str = ft_add_width(opt, str, c, a);
	if (((c == 'x') || (c == 'X')) && (opt->zero) && (opt->sharp) &&
		(!opt->less))
		str = ft_put_0x(str, c);
	return (str);
}
