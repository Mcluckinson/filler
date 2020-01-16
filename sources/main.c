/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/16 15:27:18 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_heatmap(t_plateau *plateau, int height)
{
	while (--height >= 0)
	{
		if (plateau->heatmap[height])
		{
			free(plateau->heatmap[height]);
			plateau->heatmap[height] = NULL;
		}
	}
	free(plateau->heatmap);
	plateau->heatmap = NULL;
}

int			main(void)
{
	t_env	*env;

	if (!(env = init_env()))
		return (1);
	if (!parse_player(env))
		return (ft_free(Free_env, env));
	if (!init_sub_struct(env))
		return (ft_free(Free_env, env));
	while (true)
	{
		if (!parse_plateau(env))
		{
			return (0);
		}
		if (!(env->plateau->heatmap = init_heatmap(env->plateau->height,
													env->plateau->width)))
			return (0);
		if (!parse_piece(env))
			return (0);
		math_heatmap(env);
		math_best_pos(env);
		print_coords(env->x, env->y);
		reset_coords(&env->x, &env->y);
		ft_destroy_string_arr(env->piece->map);
		free_heatmap(env->plateau, env->plateau->height);
		ft_destroy_string_arr(env->plateau->map);
	}
	ft_memdel((void *)&env->plateau);
	ft_memdel((void *)&env->piece);
	ft_memdel((void *)&env);
	return (0);
}
// rm ./sleonia.filler; clear ; make ; ./resources/filler_vm -p1 resources/players/grati.filler -p2 ./sleonia.filler -f resources/maps/map01
// rm ./sleonia.filler; clear ; make ; ./resources/filler_vm -p1 ./sleonia.filler -p2 resources/players/grati.filler -f resources/maps/map01