/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 22:30:49 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/07 12:55:49 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	ft_char_to_int(char *nbr,
		char *base_from)
{
	int						a;
	int						b;
	unsigned long long int	nb;
	int						power;

	power = ft_strlen(nbr) - 1;
	a = 0;
	b = 0;
	nb = 0;
	while (nbr[a] != '\0')
	{
		while (base_from[b] != '\0')
		{
			if (nbr[a] == base_from[b])
			{
				nb = nb + b * (ft_power(ft_strlen(base_from), power));
				--power;
			}
			++b;
		}
		b = 0;
		++a;
	}
	return (nb);
}

static char						*ft_nb_to_char(unsigned long long int nb,
		char *base_to)
{
	char					*result;
	int						len;
	unsigned long long int	tmp;

	len = 0;
	tmp = nb;
	while (tmp)
	{
		tmp = tmp / ft_strlen(base_to);
		++len;
	}
	if (!(result = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	result[len] = '\0';
	len--;
	while (len >= 0)
	{
		result[len] = base_to[nb % ft_strlen(base_to)];
		nb = nb / ft_strlen(base_to);
		--len;
	}
	return (result);
}

char							*ft_convert_base(char *nbr, char *base_from,
		char *base_to)
{
	char						*result;
	unsigned long long int		nb;

	nb = ft_char_to_int(nbr, base_from);
	if (!nb)
	{
		if (!(result = (char*)malloc(sizeof(char) + 1)))
			return (NULL);
		result[0] = base_to[0];
		result[1] = '\0';
	}
	else
		result = ft_nb_to_char(nb, base_to);
	return (result);
}
