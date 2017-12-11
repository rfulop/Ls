/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:01:56 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/07 16:04:48 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_char(char *str, int i, char c)
{
	if (str[i] == c)
		return (0);
	return (1);
}

static int		ft_count_words(char *str, char c)
{
	int a;
	int i;

	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (!(ft_check_char(str, i, c)))
		{
			while ((!(ft_check_char(str, i, c)) && str[i] != '\0'))
				++i;
		}
		else
		{
			while (ft_check_char(str, i, c) && str[i] != '\0')
				++i;
			++a;
		}
	}
	return (a);
}

static int		*ft_count_letters(char *str, int *letters, char c)
{
	int a;
	int i;
	int b;

	i = 0;
	a = 0;
	b = 1;
	while (str[i] != '\0')
	{
		if (!(ft_check_char(str, i, c)))
			while ((!(ft_check_char(str, i, c)) && str[i] != '\0'))
				++i;
		else
		{
			while (ft_check_char(str, i, c) && str[i] != '\0')
			{
				letters[a] = b;
				++b;
				++i;
			}
			++a;
			b = 1;
		}
	}
	return (letters);
}

static void		ft_add_char(char *str, char **tab, char c)
{
	int a;
	int i;
	int b;

	i = 0;
	a = 0;
	b = 0;
	while (str[i] != '\0')
	{
		if (!(ft_check_char(str, i, c)))
			while ((!(ft_check_char(str, i, c)) && str[i] != '\0'))
				++i;
		else
		{
			while (ft_check_char(str, i, c) && str[i] != '\0')
			{
				tab[a][b] = str[i];
				++i;
				++b;
			}
			tab[a][b] = '\0';
			++a;
			b = 0;
		}
	}
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		*letters;
	int		words;
	int		i;

	tab = NULL;
	if (!s)
		return (tab);
	i = 0;
	words = ft_count_words((char *)s, c);
	if (!(tab = (char**)malloc(sizeof(tab) * words + 1)))
		return (NULL);
	if (!(letters = (int*)malloc(sizeof(letters) * words)))
		return (NULL);
	ft_count_letters((char *)s, letters, c);
	letters[words] = '\0';
	while (i != words)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char*) * letters[i] + 1)))
			return (NULL);
		++i;
	}
	tab[words] = 0;
	ft_add_char((char *)s, tab, c);
	return (tab);
}
