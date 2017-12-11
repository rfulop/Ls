/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 23:11:45 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:22:32 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	ft_init_ret(t_opt *opt)
{
	opt->len = 0;
	opt->check = 0;
}

void	ft_init_opt(t_opt *opt)
{
	opt->l = 0;
	opt->ll = 0;
	opt->h = 0;
	opt->hh = 0;
	opt->j = 0;
	opt->z = 0;
	opt->sharp = 0;
	opt->zero = 0;
	opt->less = 0;
	opt->plus = 0;
	opt->space = 0;
	opt->point = 0;
	opt->width = 0;
	opt->length = 0;
	opt->prec = 0;
	opt->isneg = 0;
	opt->unicode = 0;
	opt->res = NULL;
	opt->tmp = NULL;
}
