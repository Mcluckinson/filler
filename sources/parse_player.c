/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:13:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/27 21:03:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool	parse_player(char *line, t_env *env)
{
	if (ft_strequ(line, PLAYER_1) == 1)
	{
		env->player_symbol = PLAYER_1_SYMB;
		env->opponent_symbol = PLAYER_2_SYMB;
	}
	else if (ft_strequ(line, PLAYER_2) == 1)
	{
		env->opponent_symbol = PLAYER_1_SYMB;
		env->player_symbol = PLAYER_2_SYMB;
	}
	// printf("\033[31m|%c   %c|\033[0m\n", env->opponent_symbol, env->player_symbol);
	return (true);
}

bool		parse_plateau(t_env *env)
{
	char	*line;
	char	*plateau;
	char	**split_whitespace;

	line = ft_get_line();
	split_whitespace = ft_strsplit(line, ' ');
	env->map->height = ft_atoi(split_whitespace[1]);
	env->map->width = ft_atoi(split_whitespace[2]);
	// env->map->height = 10;
	// env->map->width = 11;
	// else
		// return (false);
	// ft_destroy_string_arr(split_whitespace);
	return (true);
}
