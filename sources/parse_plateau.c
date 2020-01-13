/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plateau.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:59:32 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 02:26:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// bool		parse_plateau(t_env *env)
// {
// 	while 
// }

bool		parse_plateau_size(t_env *env)
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
	print_in_file('\0', line, -1);
	print_in_file('\0', NULL, env->plateau->width);
	print_in_file('\0', NULL, env->plateau->height);
	ft_strdel(&line);
	ft_destroy_string_arr(split);
	return (true);
}
