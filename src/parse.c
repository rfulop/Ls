/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:58:15 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_args_letter(t_env *env, char let)
{
	if (let == 'l')
		env->long_form = 1;
	else if (let == 'R')
		env->recurs = 1;
	else if (let == 'a')
		env->hiden_files = 1;
	else if (let == 'r')
		env->reverse_short = 1;
	else if (let == 't')
		env->time_short = 1;
	else if (let == 'h')
		ft_printf("Print help");
	else
	{
		ft_printf("Invalid argument\n");
		ft_printf("Print help");
		exit(EXIT_FAILURE);
	}
}

int parse_args(t_env *env, char **argv, int argc)
{
	int a;
	int b;

	a = 1;
	while (argv[a] && *argv[a] == '-')
	{
		b = 1;
		while (argv[a][b])
		{
			check_args_letter(env, argv[a][b]);
			++b;
		}
		if (b == 1)
		{
			ft_printf("Invalid argument\n");
			exit(EXIT_FAILURE);
		}
		++a;
	}
	return (a);
}
