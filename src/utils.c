/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:58:31 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char *get_perm(int oct, int type, char c)
{
	int i;
	int j;
	int  bit;
	static char perm[11] = {0};


	i = 2;
	j = 1;
	perm[0] = (type == F_DIR) ? 'd' : '-';
	bit = ((oct / ft_power(10, 4)) % 10);
	while (i >= 0)
	{
		bit = ((oct / ft_power(10, i)) % 10);
		--i;
		perm[j + 0] = bit & 4 ? 'r' : '-';
		perm[j + 1] = bit & 2 ? 'w' : '-';
		perm[j + 2] = bit & 1 ? 'x' : '-';
		j += 3;
	}
	bit = ((oct / ft_power(10, 3)) % 10);
	if (bit & 1)
		perm[9] = 't';
	perm[10] = (c ? c : 0);
	return (perm);
}
