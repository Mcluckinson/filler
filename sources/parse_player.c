/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:13:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/27 23:06:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool	parse_player(t_env *env)
{
	char	*line;

	if (!(line = ft_get_line()))
		return (false);
	if (ft_strequ(line, PLAYER_1) == 1)
	{
		env->player_symbol = PLAYER_1_SYMB_BIG;
		env->opponent_symbol = PLAYER_2_SYMB_BIG;
	}
	else if (ft_strequ(line, PLAYER_2) == 1)
	{
		env->opponent_symbol = PLAYER_1_SYMB_BIG;
		env->player_symbol = PLAYER_2_SYMB_BIG;
	}
	ft_strdel(&line);
	return (true);
}

bool		parse_plateau(t_env *env)
{
	char	*line;
	char	**split_whitespace;

	if (!(line = ft_get_line()))
		return (false);
	if (!(split_whitespace = ft_strsplit(line, ' ')))
		return (false);	
	env->map->height = ft_atoi(split_whitespace[1]);
	env->map->width = ft_atoi(split_whitespace[2]);
	ft_strdel(&line);
	ft_destroy_string_arr(split_whitespace);
	return (true);
}
