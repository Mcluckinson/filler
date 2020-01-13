/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/14 01:30:56 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	main()
{
	t_env	*env;

	if (!(env = init_env()))
		return (int_error(ERROR_MALLOC));
	if (!parse_player(env))
	{

		return (int_error(ERROR_INPUT));		
	}
	// while (true)
	// {
	// 	//
	// }
	return (0);
}

// launched ./cyuriko.filler
// $$$ exec p1 : [./cyuriko.filler]
// launched resources/players/abanlin.filler
// $$$ exec p2 : [resources/players/abanlin.filler]
// Plateau 2 4:
//     0123
// 000 .O..
// 001 ...X
// Piece 1 2:
// **
// Player with O: error on input
// Piece 1 2:
// **
// <got (X): [0, 0]
// == O fin: 0
// == X fin: 0