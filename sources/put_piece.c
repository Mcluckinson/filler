/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 05:30:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/07 18:54:01 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int fd;

static	int 	count_me_shit(t_piece *piece)
{
	int shit;
	int h;
	int w;

	shit = 0;
	h = -1;
	while (++h < piece->height)
	{
		w = -1;
		while (++w < piece->width)
		{
			if (piece->piece_map[h][w] == 1)
				shit++;
		}
	}
	return (shit);
}

static bool		put_piece(t_env *env, int h, int w, int shit)
{
	int	h_counter;
	int w_counter;
	int	crosscounter;
	int max_heat;
	int cum;

	cum = 0;
	crosscounter = 0;///////////счетчик пересечениц
	h_counter = -1;
	max_heat = 0;
	while (++h_counter < env->piece->height)
	{
		w_counter = -1;
		while (++w_counter < env->piece->width)
		{
			if (w + w_counter < env->map->width && h + h_counter < env->map->height)
			{
				if (env->map->heatmap[h + h_counter][w + w_counter] == OPPONENT_HEAT && env->piece->piece_map[h_counter][w_counter] == 1)
				{
					ft_putstr_fd("SASI HUI", fd);
					return (false);
				}

				if (env->map->heatmap[h + h_counter][w + w_counter] == MY_HEAT && env->piece->piece_map[h_counter][w_counter] == 1)//
				{
					++crosscounter;
					cum++;
				}
				if (env->piece->piece_map[h_counter][w_counter] == 1 && env->map->heatmap[h + h_counter][w + w_counter] > max_heat)
				{
					max_heat = env->map->heatmap[h + h_counter][w + w_counter];
					cum++;
					ft_putstr_fd("max_heat ", fd);
					ft_putnbr_fd(max_heat, fd);
					ft_putchar_fd('\n', fd);
				}
			}


		}
	}
	ft_putstr_fd("crosscounter ", fd);
	ft_putnbr_fd(crosscounter, fd);
	ft_putchar_fd('\n', fd);
	if (max_heat > env->max_heat && crosscounter == 1 && shit == cum) //тут что-то менял
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
	int shit;

	h = -1;
	shit = count_me_shit(env->piece);
	env->max_heat = 0;
	while (++h < env->map->height)
	{
		w = -1;
		while (++w < env->map->width)
		{
			put_piece(env, h, w, shit);
	//		if (!(p))
	//			return (false);
		}
	}
	return (check_piece(env));
}
