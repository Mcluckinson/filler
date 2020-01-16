/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:21:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 17:11:43 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			print_coords(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void			reset_coords(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

static void		free_heatmap(t_plateau *plateau, int height)
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

static void		ft_destroy_all(t_env *env)
{
	if (env)
	{
		if (env->piece)
		{
			if (env->piece->map)
				ft_destroy_string_arr(env->piece->map);
			ft_memdel((void *)&env->piece);
		}
		if (env->plateau)
		{
			if (env->plateau->map)
				ft_destroy_string_arr(env->plateau->map);
			if (env->plateau->heatmap)
				free_heatmap(env->plateau, env->plateau->height);
			ft_memdel((void *)&env->plateau);
		}
		ft_memdel((void *)&env);
	}
}

int				ft_free(int code, t_env *env)
{
	if (code == End_turn)
	{
		ft_destroy_string_arr(env->piece->map);
		free_heatmap(env->plateau, env->plateau->height);
		ft_destroy_string_arr(env->plateau->map);
		return (0);
	}
	else if (code == Endgame)
	{
		ft_memdel((void *)&env->plateau);
		ft_memdel((void *)&env->piece);
		ft_memdel((void *)&env);
		return (0);
	}
	else if (code == Fail)
		ft_destroy_all(env);
	return (0);
}
