/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 05:30:04 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 09:37:33 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool		put_piece(t_env *env, int h, int w)
{
	int	h_counter;
	int w_counter;
	int	crosscounter;
	int max_heat;

	crosscounter = 0;
	h_counter = -1;
	while (++h_counter < env->piece->height)
	{
		w_counter = -1;
		while (++w_counter < env->piece->width)
		{
			if (env->map->heatmap[h + h_counter][w + w_counter] == -1 
			&& env->piece->piece_map[h_counter][w_counter] == 1)
				crosscounter++;
			if ((env->map->heatmap[h + h_counter][w + w_counter] == -2 
			&& env->piece->piece_map[h_counter][w_counter] == 1))
				return (false);
			if (env->map->heatmap[h + h_counter][w + w_counter] > 0 
			&& env->piece->piece_map[h_counter][w_counter] == 1 && 
			env->map->heatmap[h + h_counter][w + w_counter] < env->max_heat)
				max_heat = env->map->heatmap[h + h_counter][w + w_counter];
		}
	}
	if (max_heat > env->max_heat || crosscounter == 1) //тут что-то менял
	{
		env->max_heat = max_heat;
		env->best_y = h;
		env->best_x = w;
		return (true);
	}
	return (false);
}

static bool		check_piece(t_env *env)
{
	if (env->best_x > -1 && env->best_y > -1 && env->max_heat > 0)
		return (true);
	return (false);
}

bool		try_it_out(t_env *env) //хуево работает
{
	int	h;
	int	w;

	h = -1;
	env->max_heat = 2147483647;
	while (++h < env->map->height - env->piece->height)
	{
		w = -1;
		while (++w < env->map->width - env->piece->width)
		{
			if (!(put_piece(env, h, w)))
				return (false);
		}
	}
	return (check_piece(env));
}
