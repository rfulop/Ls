/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:23:36 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/07 13:11:11 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_b(va_list ap, t_opt *opt)
{
	char			*tmp;
	char			*str;
	unsigned int	b;

	b = va_arg(ap, unsigned int);
	tmp = ft_itoa(b);
	str = ft_convert_base(tmp, DEC, BIN);
	write(1, str, (int)ft_strlen(str));
	opt->len += (int)ft_strlen(str);
	ft_memdel((void*)&str);
	ft_memdel((void*)&tmp);
}
