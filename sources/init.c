/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:48:50 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/27 20:02:38 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_piece		*init_piece(void)
{
	t_piece			*piece;

	if (!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
		return (NULL);
	piece->x = 0;
	piece->y = 0;
	piece->piece = NULL;
	piece->piece_map = NULL;
	piece->x_pos = 0;
	piece->y_pos = 0;
	return (piece);
}

static t_map		*init_map(void)
{
	t_map			*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->map = NULL;
	map->heatmap = NULL;
	return (map);
}

t_env				*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->p_num = 0;
	env->player_symbol = 0;
	env->opponent_symbol = 0;
	if (!(env->map = init_map()))
	{
		ft_memdel((void *)&env);
		return (NULL);
	}
	if (!(env->piece = init_piece()))
	{
		ft_memdel((void *)&env->map);
		ft_memdel((void *)&env);
		return (NULL);
	}
	return (env);
}
