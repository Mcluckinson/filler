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
	int		h;
	int		w;
	int		dist;
	int		min_distanse;

	min_distanse = INT32_MAX;
	h = -1;
	while (++h < plateau->height)
	{
		w = -1;
		while (++w < plateau->width)
		{
			if (plateau->heatmap[h][w] == ENEMY_HEAT)
			{
				dist = abs(h - x) + abs(w - y);
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
	while (++h < env->plateau->height)
	{
		w = -1;
		while (++w < env->plateau->width)
		{
			if (env->plateau->map[h][w] == env->my_symb
				|| env->plateau->map[h][w] == env->my_symb + 32)
				env->plateau->heatmap[h][w] = MY_HEAT;
			else if (env->plateau->map[h][w] == env->enemy_symb
				|| env->plateau->map[h][w] == env->enemy_symb + 32)
				env->plateau->heatmap[h][w] = ENEMY_HEAT;
		}
	}
}

bool		math_heatmap(t_env *env)
{
	math_players_pos(env);
	// print_in_file('\0', NULL, env->plateau->map, NULL, env->plateau->height, env->plateau->width, -1);
	// print_in_file('\0', NULL, NULL, env->plateau->heatmap, env->plateau->height, env->plateau->width, -1);
	count_heatmap(env->plateau);
	return (true);
}