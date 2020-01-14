/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/14 08:49:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(int ac, char **av)
{
	t_env	*env;

	if (!(env = init_env()))
		return (1);
	if (!parse_player(env))
		return (ft_free(env));
	while (true)
	{
		if (!init_sub_struct(env))
			return (ft_free(env));
		if (!parse_plateau(env))
			return (int_error(ERROR_INPUT));
		if (!(env->plateau->heatmap = init_heatmap(env->plateau->height,
													env->plateau->width)))
			return (ft_free(env));
		if (!parse_piece(env))
			return (ft_free(env));
		math_heatmap(env);
		math_best_pos(env);
		print_coords(env->x, env->y);
		// ft_free(env);
	}
	return (0);
}
