/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_heatmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:04:57 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 06:22:41 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	math_manhattan_dist(int x, int y, t_plateau *plateau)
{
	int		x_counter;
	int		y_counter;
	int		dist;
	int		min_distanse;

	min_distanse = 2147483647;
	x_counter = -1;
	while (++x_counter < plateau->height)
	{
		y_counter = -1;
		while (++y_counter < plateau->width)
		{
			if (plateau->heatmap[x_counter][y_counter] == ENEMY_HEAT)
			{
				dist = abs(x_counter - x) + abs(y_counter - y);
				if (dist < min_distanse)
					min_distanse = dist;
			}
		}
	}
	return (min_distanse);
}

static void	count_heatmap(t_plateau *plateau)
{
	int		x;
	int		y;

	x = -1;
	while (++x < plateau->height)
	{
		y = -1;
		while (++y < plateau->width)
		{
			if (plateau->heatmap[x][y] == 0)
				plateau->heatmap[x][y] = math_manhattan_dist(x, y, plateau);
		}
	}
}


static void	math_players_pos(t_env *env)
{
	int		h;
	int		w;

	h = -1;
	w = -1;
	while (++h < env->plateau->height)
	{
		while (++w < env->plateau->width)
		{
			if (env->plateau->map[h][w] == env->my_symb
				|| env->plateau->map[h][w] == env->my_symb + 40)
				env->plateau->heatmap[h][w] = MY_HEAT;
			else if (env->plateau->map[h][w] == env->enemy_symb
				|| env->plateau->map[h][w] == env->enemy_symb + 40)
				env->plateau->heatmap[h][w] = ENEMY_HEAT;
		}

	}
}

bool		math_heatmap(t_env *env)
{
	math_players_pos(env);
	count_heatmap(env->plateau);
	return (true);
}