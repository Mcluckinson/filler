/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_best_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 07:03:09 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 08:55:08 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		math_sum(int x, int y, t_plateau *plateau, t_piece *piece)
{
	t_math_sum	math;

	math.y = -1;
	math.sum = 0;
	math.count = 0;
	while (++math.y < piece->height)
	{
		math.x = -1;
		while (++math.x < piece->width)
		{
			if (piece->map[math.y][math.x] == '*')
			{
				if ((y + math.y) < 0 || (y + math.y) >= plateau->height
					|| (x + math.x) < 0 || (x + math.x) >= plateau->width
					|| plateau->heatmap[y + math.y][x + math.x] == ENEMY_HEAT)
					return (-1);
				if (plateau->heatmap[y + math.y][x + math.x] == MY_HEAT)
					math.count++;
				math.sum += plateau->heatmap[y + math.y][x + math.x];
			}
		}
	}
	return ((math.count == 1) ? math.sum : -1);
}

void			math_best_pos(t_env *env)
{
	int			x;
	int			y;
	int			sum;
	int			min_sum;

	min_sum = INT32_MAX;
	y = -(env->piece->height) - 1;
	while (++y < env->piece->height + env->plateau->height)
	{
		x = -(env->piece->width) - 1;
		while (++x < env->piece->width + env->plateau->width)
		{
			sum = math_sum(x, y, env->plateau, env->piece);
			if (sum != -1 && sum < min_sum)
			{
				env->x = x;
				env->y = y;
				min_sum = sum;
			}
		}
	}
}
