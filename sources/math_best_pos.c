/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_best_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:03:09 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 08:19:54 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	math_sum(int x, int y, t_env *env)
{
	int		x_piece;
	int		y_piece;
	int		sum;
	int		count;

	y_piece = -1;
	sum = 0;
	count = 0;
	while (++y_piece < env->piece->height)
	{
		x_piece = -1;
		while (++x_piece < env->piece->width)
		{
			if (env->piece->map[y_piece][x_piece] == '*')
			{
				if ((y + y_piece) < 0 || (y + y_piece) >= env->plateau->height
					|| (x + x_piece) < 0 || (x + x_piece) >= env->plateau->width
					|| env->plateau->heatmap[y + y_piece][x + x_piece] == ENEMY_HEAT)
					return (-1);
				if (env->plateau->heatmap[y + y_piece][x + x_piece] == MY_HEAT)
					count++;
				sum += env->plateau->heatmap[y + y_piece][x + x_piece];
			}
		}
	}
	return ((count == 1) ? sum : -1);
}

void		math_best_pos(t_env *env)
{
	int		x;
	int		y;
	int		sum;
	int		min_sum;

	min_sum = INT32_MAX;
	y = -(env->piece->height) - 1;
	while (++y < env->piece->height + env->plateau->height)
	{
		x = -(env->piece->width) - 1;
		while (++x < env->piece->width + env->plateau->width)
		{
			sum = math_sum(x, y, env);
			if (sum != -1 && sum < min_sum)
			{
				env->x = x;
				env->y = y;
				min_sum = sum;
			}
		}
	}
}
