/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plateau.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:59:32 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 07:02:13 by sleonia          ###   ########.fr       */
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
	// print_in_file('\0', line, NULL, NULL, -1);
	// print_in_file('\0', NULL, NULL, NULL, env->plateau->height);
	// print_in_file('\0', NULL, NULL, NULL, env->plateau->width);
	ft_strdel(&line);
	ft_destroy_string_arr(split);
	return (true);
}

bool		parse_plateau(t_env *env)
{
	int		i;
	char	*line;
	char	**split;

	if (!parse_plateau_size(env))
		return (false);
	if (get_next_line(0, &line) != 1)
		return (false);
	ft_strdel(&line);
	i = -1;
	if (!(env->plateau->map = init_map(env->plateau->height + 1)))
	{
		ft_strdel(&line);
		return (false);
	}		
	while (++i < env->plateau->height)
	{
		if (get_next_line(0, &line) != 1)
			return (false);		
		// print_in_file('\0', line, NULL, NULL, -1);
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
	// print_in_file('\0', "env->plateau->map", env->plateau->map, NULL, -1);
	return (true);
}
