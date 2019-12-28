/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_heatmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:49:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 03:17:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int fd;

static int	calc_manhattan_dist(int x, int y, t_map *map)
{
	int		x_counter;
	int		y_counter;
	int		dist;
	int		min_distanse;

	min_distanse = 2147483647;
	x_counter = -1;
	while (++x_counter < map->height)
	{
		y_counter = -1;
		while (++y_counter < map->width)
		{
			if (map->heatmap[x_counter][y_counter] == OPPONENT_HEAT)
			{
				dist = abs(x_counter - x) + abs(y_counter - y);
				if (dist < min_distanse)
					min_distanse = dist;
			}
		}
	}
	return (min_distanse);
}

void		count_heatmap(t_map *map)
{
	int		x;
	int		y;

	x = -1;
	while (++x < map->height)
	{
		y = -1;
		while (++y < map->width)
		{
			if (map->heatmap[x][y] == 0)
				map->heatmap[x][y] = calc_manhattan_dist(x, y, map);
		}
	}
}
