/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:57:33 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/26 18:57:33 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	free_split_int(int **split)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	if (!split)
		return (0);
	while (split[y])
	{
		free(split[y]);
		y++;
	}
	free(split);
	return (0);
}

int 	free_all_things(t_map *map, t_piece *piece, t_data *data)
{
	if (map)
		free_map(map);
	if (piece)
		free_piece(piece);
	if (data)
		free_data(data);
	return (0);
}