/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 05:30:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/07 18:25:56 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int fd;

static bool		put_piece(t_env *env, int h, int w)
{
	int	h_counter;
	int w_counter;
	int	crosscounter;
	int max_heat;

	crosscounter = 0;///////////счетчик пересечениц
	h_counter = -1;
	max_heat = 0;
	while (++h_counter < env->piece->height)
	{
		w_counter = -1;
		while (++w_counter < env->piece->width)
		{
			if (env->map->heatmap[h + h_counter][w + w_counter] == OPPONENT_HEAT && env->piece->piece_map[h_counter][w_counter] == 1)
			{
				ft_putstr_fd("SASI HUI", fd);
				return (false);
			}

			if (env->map->heatmap[h + h_counter][w + w_counter] == MY_HEAT && env->piece->piece_map[h_counter][w_counter] == 1)//
			{
				++crosscounter;

			}
			if (env->piece->piece_map[h_counter][w_counter] == 1 && env->map->heatmap[h + h_counter][w + w_counter] > max_heat)
			{
				max_heat = env->map->heatmap[h + h_counter][w + w_counter];
				ft_putstr_fd("max_heat ", fd);
				ft_putnbr_fd(max_heat, fd);
				ft_putchar_fd('\n', fd);
			}

		}
	}
	ft_putstr_fd("crosscounter ", fd);
	ft_putnbr_fd(crosscounter, fd);
	ft_putchar_fd('\n', fd);
	if (max_heat > env->max_heat && crosscounter == 1) //тут что-то менял
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
	env->max_heat = 0;
	while (++h < env->map->height - env->piece->height + 1)
	{
		w = -1;
		while (++w < env->map->width - env->piece->width + 1)
		{
			put_piece(env, h, w);
	//		if (!(p))
	//			return (false);
		}
	}
	return (check_piece(env));
}
