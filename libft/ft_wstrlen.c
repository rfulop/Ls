/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 00:31:46 by lchety            #+#    #+#             */
/*   Updated: 2017/03/30 16:16:58 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t length;

	length = 0;
	while (*(s + length) != '\0')
		length++;
	return (length);
}
