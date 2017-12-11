/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 19:56:07 by rfulop            #+#    #+#             */
/*   Updated: 2017/02/12 21:14:28 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(unsigned long int nb, int pw)
{
	if (pw < 0)
		return (0);
	else if (!pw)
		return (1);
	else
		nb = nb * ft_power(nb, pw - 1);
	return (nb);
}
