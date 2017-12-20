/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 23:44:43 by rfulop            #+#    #+#             */
/*   Updated: 2017/12/16 05:57:55 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	init_env(t_env *env)
{
	env->long_form = 0;
	env->recurs = 0;
	env->hiden_files = 0;
	env->reverse_short = 0;
	env->time_short = 0;
	env->path = NULL;
	env->max_links = 0;
	env->max_user = 0;
	env->max_gr = 0;
	env->max_size = 0;
}
