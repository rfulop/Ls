/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hou.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:09:02 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:23:51 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_put_0x(char *str, char c)
{
	if (c == 'x')
		str = ft_stradd("0x", str, 2);
	else
		str = ft_stradd("0X", str, 2);
	return (str);
}

char	*ft_print_xou(t_opt *opt, t_ulong n, char c)
{
	char	*str;

	if (c == 'X')
		str = ft_conv_hex(ft_itoa_ull(n), HEX1);
	else if (c == 'x')
		str = ft_conv_hex(ft_itoa_ull(n), HEX2);
	else if (c == 'o')
		str = ft_conv_oct(ft_itoa_ull(n), OCT);
	else
		str = ft_itoa_ull(n);
	if ((opt->prec && n) || (opt->sharp && c == 'o'))
		str = ft_prec(opt, str, c);
	if (n && (c != 'u') && opt->sharp && !opt->zero)
	{
		if (c == 'X' || c == 'x')
			str = ft_put_0x(str, c);
		else
			str = ft_stradd("0", str, 2);
	}
	if (opt->width)
		str = ft_width(opt, str, c);
	if ((!(!n && opt->prec) || (opt->sharp && c == 'o')))
		write(1, str, (int)ft_strlen(str));
	return (str);
}
