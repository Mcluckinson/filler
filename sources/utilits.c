/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:21:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 09:41:50 by sleonia          ###   ########.fr       */
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

int		ft_free(int free_code, t_env *env)
{
	if (free_code == Free_sub_struct
		|| free_code == Free_plateau
		|| free_code == Free_piece)
	{
		if (free_code == Free_piece)
		{
			ft_destroy_string_arr(env->piece->map);
			ft_memdel((void *)&env->piece);
		}
		if (free_code == Free_plateau)
		{
			ft_destroy_string_arr(env->plateau->map);
			ft_destroy_int_arr(env->plateau->heatmap, env->plateau->height);
			ft_memdel((void *)&env->plateau);
		}
	}
	if (free_code == Free_all || free_code == Free_env)
		ft_memdel((void *)&env->plateau);
	return (1);
}
