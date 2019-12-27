/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_heat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:49:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 01:04:49 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool		check_up(int x, int y, t_map *map)
{
	if (!x)
		return (false);
	if (map->heatmap[x - 1][y] == OPPONENT_HEAT)
	{
		map->heatmap[x][y] = 1;
		return (true);
	}
	else if (map->heatmap[x - 1][y] != MY_HEAT)
	{
		map->heatmap[x][y] = map->heatmap[x - 1][y] + 1;
		return (true);
	}
	return (false);
}

static bool		check_down(int x, int y, t_map *map)
{
	if (x + 1 == map->height)
		return (false);
	if (map->heatmap[x + 1][y] == OPPONENT_HEAT)
	{
		map->heatmap[x][y] = 1;
		return (true);
	}
	else if (map->heatmap[x + 1][y] != MY_HEAT)
	{
		map->heatmap[x][y] = map->heatmap[x + 1][y] + 1;
		return (true);
	}
	return (false);
}

static bool		check_right(int x, int y, t_map *map)
{
	if (y + 1 == map->width)
		return (false);
	if (map->heatmap[x][y + 1] == OPPONENT_HEAT)
	{
		map->heatmap[x][y] = 1;
		return (true);
	}
	else if (map->heatmap[x][y + 1] != MY_HEAT)
	{
		map->heatmap[x][y] = map->heatmap[x][y + 1] + 1;
		return (true);
	}
	return (false);
}

static bool		check_left(int x, int y, t_map *map)
{
	if (!y)
		return (false);
	if (map->heatmap[x][y - 1] == OPPONENT_HEAT)
	{
		map->heatmap[x][y] = 1;
		return (true);
	}
	else if (map->heatmap[x][y - 1] != MY_HEAT)
	{
		map->heatmap[x][y] = map->heatmap[x][y - 1] + 1;
		return (true);
	}
	return (false);
}

void			count_heat(int x, int y, t_map *map)
{
	if (map->heatmap[x][y])
		return ;
	if (check_up(x, y, map))
		return ;
	if (check_down(x, y, map))
		return ;
	if (check_right(x, y, map))
		return ;
	if (check_left(x, y, map))
		return ;
		
}
