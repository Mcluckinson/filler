/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_heatmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:43:08 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 00:37:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		**create_heatmap(int height, int width)
{
	int			h_counter;
	int			**heatmap;

	if (!(heatmap = (int **)ft_memalloc(sizeof(int *) * height)))
		return (NULL);
	h_counter = -1;
	while (++h_counter < height)
	{
		if (!(heatmap[h_counter] = (int *)ft_memalloc(sizeof(int) * width)))
		{
			ft_destroy_int_arr(heatmap, h_counter);
			return (NULL);
		}
	}
	return (heatmap);
}

static void		fill_heatmap(t_env *env)
{
	int	w_counter;
	int	h_counter;

	h_counter = -1;
	while (++h_counter < env->map->height)
	{
		w_counter = -1;
		while (++w_counter < env->map->width)
		{
			count_heat(h_counter, w_counter, env->map);
		}
	}
}

bool			init_heatmap(t_env *env)
{
	int	w_counter;
	int	h_counter;

	h_counter = -1;
	if (!(env->map->heatmap = create_heatmap(env->map->height, env->map->width)))
		return (false);
	while (++h_counter < env->map->height)
	{
		w_counter = -1;
		while (++w_counter < env->map->width)
		{
			if (env->map->map[h_counter][w_counter] == env->player_symbol || 
			env->map->map[h_counter][w_counter] == env->player_symbol + 40)
				env->map->heatmap[h_counter][w_counter] = MY_HEAT;
			else if (env->map->map[h_counter][w_counter] == env->opponent_symbol || 
			env->map->map[h_counter][w_counter] == env->opponent_symbol + 40)
				env->map->heatmap[h_counter][w_counter] = OPPONENT_HEAT;
		}
	}
	fill_heatmap(env);
	return (true);
}
