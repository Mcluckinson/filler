/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:52:45 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/15 21:50:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static bool		parse_piece_size(t_env *env)
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
	env->piece->height = ft_atoi(split[1]);
	env->piece->width = ft_atoi(split[2]);
	ft_strdel(&line);
	ft_destroy_string_arr(split);
	return (true);
}

static bool		read_piece(t_env *env)
{
	int			i;
	char		*line;

	i = -1;
	if (!(env->piece->map = init_map(env->piece->height + 1)))
		return (false);
	while (++i < env->piece->height)
	{
		if (get_next_line(0, &line) != 1)
			return (false);
		env->piece->map[i] = line;
	}
	return (true);
}

bool			parse_piece(t_env *env)
{
	if (!parse_piece_size(env))
		return (false);
	if (!read_piece(env))
		return (false);
	return (true);
}
