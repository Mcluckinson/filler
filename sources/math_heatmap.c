/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_heatmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 08:47:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 16:12:24 by sleonia          ###   ########.fr       */
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
			if (ft_toupper(env->plateau->map[h][w]) == env->my_symb)
				env->plateau->heatmap[h][w] = MY_HEAT;
			else if (ft_toupper(env->plateau->map[h][w]) == env->enemy_symb)
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
