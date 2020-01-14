/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:48:50 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 08:48:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				**init_heatmap(int height, int width)
{
	int			**heatmap;
	int			i;

	i = 0;
	if (!(heatmap = (int **)ft_memalloc(sizeof(int *) * height)))
		return (NULL);
	i = -1;
	while (++i < height)
	{
		if (!(heatmap[i] = (int *)ft_memalloc(sizeof(int) * width)))
		{
			ft_destroy_int_arr(heatmap, i);
			return (NULL);
		}
	}
	return (heatmap);
}

char			**init_map(int height)
{
	char		**map;

	if (!(map = (char **)ft_memalloc(sizeof(char *) * height)))
		return (NULL);
	return (map);
}

bool			init_sub_struct(t_env *env)
{
	if (!(env->plateau = (t_plateau *)ft_memalloc(sizeof(t_plateau))))
		return (false);
	if (!(env->piece = (t_piece *)ft_memalloc(sizeof(t_piece))))
	{
		ft_memdel((void *)&env->plateau);
		return (false);
	}
	return (true);
}

t_env			*init_env(void)
{
	t_env		*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	return (env);
}
