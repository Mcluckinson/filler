/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:13:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/27 19:44:33 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool	parse_player(t_env *env)
{
	char *line;

	if (get_next_line(0, &line))
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
	}
	else
		return (false);
	return (true);
}