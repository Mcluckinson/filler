/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 19:13:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/27 19:17:11 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool	parse_player(t_env *env)
{
	int	res = 0;
	// env->;
	char *line;
	if ((res = get_next_line(0, &line)) == 1)
	{
		if (ft_strequ(line, PLAYER_1) == 1)
			res = 1;// ft_exit("LOL1");
		else if (ft_strequ(line, PLAYER_2) == 1)
			res = 2;// ft_exit("LOL2");
	}
	printf("\033[31m%d\n", res);
	if (res == 1)
		ft_exit("LOL1");
	else if (res == 2)
		ft_exit("LOL2");
}