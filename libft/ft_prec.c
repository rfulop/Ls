/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:25:12 by rfulop            #+#    #+#             */
/*   Updated: 2017/04/29 03:23:37 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*ft_no_prec(t_opt *opt, char *str, char c)
{
	if (opt->width)
		str = ft_width(opt, str, c);
	write(1, str, (int)ft_strlen(str));
	return (str);
}

char	*ft_prec_s(t_opt *opt, char *str)
{
	int		a;
	int		len;

	len = (int)ft_strlen(str);
	if (opt->prec == -1)
		ft_strclr(str);
	else if (len > opt->prec && opt->prec != -1)
	{
		a = 0;
		while (a != opt->prec)
			++a;
		while (a != len)
		{
			str[a] = '\0';
			++a;
		}
	}
	return (str);
}

char	*ft_put_zero_s(t_opt *opt, char *str, int a, int flag)
{
	int len;

	len = (int)ft_strlen(str) - flag;
	while ((len + a) != opt->prec)
	{
		if (!a && flag)
			str = ft_stradd("0", str, 3);
		else
			str = ft_stradd("0", str, 2);
		++a;
	}
	return (str);
}

char	*ft_prec(t_opt *opt, char *str, char c)
{
	int		a;
	int		len;
	int		flag;

	len = (int)ft_strlen(str);
	a = 0;
	flag = 0;
	if (str[0] == '-')
	{
		flag++;
		len--;
	}
	if (len < opt->prec)
	{
		if (c == 'o' && opt->sharp)
			a++;
		str = ft_put_zero_s(opt, str, a, flag);
	}
	if (flag)
		str = ft_stradd("-", str, 2);
	return (str);
}
