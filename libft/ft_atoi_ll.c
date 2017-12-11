/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:56:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/01/17 18:23:00 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int		ft_atoi_ll(char *str)
{
	int						a;
	unsigned long long int	nb;
	int						negatif;

	a = 0;
	nb = 0;
	negatif = 1;
	while (str[a] == '\n' || str[a] == '\t' || str[a] == '\v' ||
	str[a] == ' ' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == 45)
		negatif = -1;
	if ((str[a] == 43) || (str[a] == 45))
		a++;
	while ((str[a] != '\0') && ((str[a] >= 48) && (str[a] <= 57)))
	{
		nb = nb * 10 + str[a] - 48;
		a++;
	}
	return (nb * negatif);
}
