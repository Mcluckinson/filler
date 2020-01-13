/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 17:48:50 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 02:34:30 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				**init_heat_map(int height, int width)
{
	int			**heat_map;
	int			i;

	i = 0;
	if (!(heat_map = (int **)ft_memalloc(sizeof(int *) * height)))
		return (NULL);
	i = -1;
	while (++i < height)
	{
		if (!(heat_map[i] = (int *)ft_memalloc(sizeof(int) * width)))
		{
			ft_destroy_int_arr(heat_map, i);
			return (NULL);
		}
	}
	return (heat_map);
}

char			**init_map(int height)
{
	char	**map;

	if (!(map = ft_memalloc(sizeof(char*) * height)))
		return (NULL);
	return (map);
}

t_plateau		*init_plateau(void)
{
	t_plateau	*plateau;

	if (!(plateau = (t_plateau *)ft_memalloc(sizeof(t_plateau))))
		return (NULL);
	return (plateau);
}

t_env			*init_env(void)
{
	t_env		*env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	
	return (env);
}
