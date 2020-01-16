/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/16 04:31:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
			return (ft_free(Free_all, env));
		if (!(env->plateau->heatmap = init_heatmap(env->plateau->height,
													env->plateau->width)))
			return (ft_free(Free_all, env));
		if (!parse_piece(env))
			return (ft_free(Free_all, env));
		math_heatmap(env);
		math_best_pos(env);
		print_coords(env->x, env->y);
		reset_coords(&env->x, &env->y);
		// ft_destroy_string_arr(env->piece->map);
		// ft_destroy_string_arr(env->plateau->map);
		// ft_destroy_int_arr(env->plateau->heatmap, env->plateau->height - 1);
	}
	// ft_memdel((void *)&env->plateau);
	// ft_memdel((void *)&env->piece);
	// ft_memdel((void *)&env);
	return (0);
}
// rm ./sleonia.filler; clear ; make ; ./resources/filler_vm -p1 resources/players/grati.filler -p2 ./sleonia.filler -f resources/maps/map01
// rm ./sleonia.filler; clear ; make ; ./resources/filler_vm -p1 ./sleonia.filler -p2 resources/players/grati.filler -f resources/maps/map01