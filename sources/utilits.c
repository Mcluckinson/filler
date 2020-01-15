/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:21:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 00:02:44 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	reset_coords(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

int		ft_free(int code, t_env *env)
{
	if (code == Free_sub_struct
		|| code == Free_plateau
		|| code == Free_piece
		|| code == Free_all)
	{
		if (code == Free_piece || code == Free_sub_struct 
			|| code == Free_all)
		{
			ft_destroy_string_arr(env->piece->map);
		}
		if (code == Free_plateau || code == Free_sub_struct
			|| code == Free_all)
		{
			ft_destroy_string_arr(env->plateau->map);
			ft_destroy_int_arr(env->plateau->heatmap, env->plateau->height);
		}
	}
	if (code == Free_all || code == Free_env)
		ft_memdel((void *)&env->plateau);
	return (1);
}
