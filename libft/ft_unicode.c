/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 02:51:26 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:25:59 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_print_unicode_bis(t_opt *opt, wchar_t a)
{
	opt->tmp[0] = (((a >> 18) & 0x07) | 0xF0);
	opt->tmp[1] = (((a >> 12) & 0x3F) | 0x80);
	opt->tmp[2] = (((a >> 6) & 0x3F) | 0x80);
	opt->tmp[3] = (((a >> 0) & 0x3F) | 0x80);
	opt->tmp[4] = '\0';
}

void	ft_print_unicode(t_opt *opt, wchar_t a, int byt)
{
	opt->tmp = NULL;
	opt->tmp = ft_strnew(5);
	if (byt <= 7)
	{
		opt->tmp[0] = (((a >> 0) & 0x7F) | 0x00);
		opt->tmp[1] = '\0';
	}
	else if (byt <= 11)
	{
		opt->tmp[0] = (((a >> 6) & 0x1F) | 0xC0);
		opt->tmp[1] = (((a >> 0) & 0x3F) | 0x80);
		opt->tmp[2] = '\0';
	}
	else if (byt <= 16)
	{
		opt->tmp[0] = (((a >> 12) & 0x0F) | 0xE0);
		opt->tmp[1] = (((a >> 6) & 0x3F) | 0x80);
		opt->tmp[2] = (((a >> 0) & 0x3F) | 0x80);
		opt->tmp[3] = '\0';
	}
	else if (byt <= 21)
		ft_print_unicode_bis(opt, a);
}
