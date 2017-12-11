/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 14:16:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/03/16 02:00:41 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewchr(char *line, char c)
{
	int		a;
	char	*name;

	a = 0;
	while (line[a] && line[a] != c)
		++a;
	if (!(name = (char*)malloc(sizeof(char) * a + 1)))
		return (NULL);
	a = 0;
	while (line[a] && line[a] != c)
	{
		name[a] = line[a];
		++a;
	}
	name[a] = '\0';
	return (name);
}
