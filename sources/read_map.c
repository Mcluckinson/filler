/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:09:49 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 08:42:06 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	**create_map(int height, int width)
{
	char	**map;

	if (!(map = ft_memalloc(sizeof(char*) * height)))
		return (NULL);
	return (map);
}

bool		read_map(t_env *env)
{
	int		i;
	char	*line;
	char	**split;

	i = -1;
	if (!(skip_line(1)))
		return (false);
	if (!(env->map->map = create_map(env->map->height, env->map->width)))
		return (false);
	while (++i < env->map->height)
	{
		if (!(line = ft_get_line()))
			return (false);			
		if (!(split = ft_strsplit(line, ' ')))
		{
			ft_strdel(&line);
			ft_destroy_string_arr(env->map->map);
			return (false);
		}
		env->map->map[i] = ft_strdup(split[1]);//////////protect this shit
		ft_strdel(&line);
		ft_destroy_string_arr(split);
	}
	return (true);
}
