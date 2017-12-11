/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 17:28:52 by lchety            #+#    #+#             */
/*   Updated: 2017/03/30 16:18:22 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c < 0x7f)
		ft_putchar(c);
	else if (c < 0x800)
	{
		ft_putchar((c >> 6) | 0xC0);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else if (c < 0x10000)
	{
		ft_putchar((c >> 12) | 0xE0);
		ft_putchar(((c >> 6) & 0x3f) | 0x80);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else if (c < 0x200000)
	{
		ft_putchar((c >> 18) | 0xF0);
		ft_putchar(((c >> 12) & 0x3f) | 0x80);
		ft_putchar(((c >> 6) & 0x3f) | 0x80);
		ft_putchar((c & 0x3f) | 0x80);
	}
}
