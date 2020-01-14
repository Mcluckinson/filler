/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plateau.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:59:32 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 09:02:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool	parse_plateau_size(t_env *env)
{
	char	*line;
	char	**split;

	if (get_next_line(0, &line) != 1)
		return (false);
	if (!(split = ft_strsplit(line, ' ')))
	{
		ft_strdel(&line);
		return (false);
	}
	env->plateau->height = ft_atoi(split[1]);
	env->plateau->width = ft_atoi(split[2]);
	ft_strdel(&line);
	ft_destroy_string_arr(split);
	return (true);
}

static bool	read_plateau_map(t_env *env)
{
	int		i;
	char	*line;
	char	**split;

	i = -1;
	while (++i < env->plateau->height)
	{
		if (get_next_line(0, &line) != 1)
			return (false);
		if (!(split = ft_strsplit(line, ' ')))
		{
			ft_strdel(&line);
			return (false);
		}
		if (!(env->plateau->map[i] = ft_strdup(split[1])))
		{
			ft_strdel(&line);
			ft_destroy_string_arr(split);
			return (false);
		}
		ft_strdel(&line);
		ft_destroy_string_arr(split);
	}
}

bool		parse_plateau(t_env *env)
{
	char	*line;

	if (!parse_plateau_size(env))
		return (false);
	if (get_next_line(0, &line) != 1)
		return (false);
	ft_strdel(&line);
	if (!(env->plateau->map = init_map(env->plateau->height + 1)))
	{
		ft_strdel(&line);
		return (false);
	}
	if (!read_plateau_map(env))
		return (false);
	return (true);
}
