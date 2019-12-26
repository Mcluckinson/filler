/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_heat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:51:28 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/26 19:43:47 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	**transform_piece_to_int(char **line, int x, int y)
{
	int **piece;
	int 	x_counter;
	int 	y_counter;

	x_counter = 0;

	if (!(piece = ft_memalloc(sizeof(int*) * x)))
		return (NULL);
	while (x_counter < x)
	{
		y_counter = 0;
		if (!(piece[x_counter] = ft_memalloc(sizeof(int) * y)))//////leaks, needs checking
			return (0);
		while (y_counter < y)
		{
			if (line[x_counter][y_counter] == '*')
				piece[x_counter][y_counter] = 1;
			y_counter++;
		}
		x_counter++;
	}
	return (piece);
}

int 		**create_heatmap(char **map, int x, int y)
{
	int x_counter;
	int **heatmap;

	x_counter = 0;
	if (!(heatmap = ft_memalloc(sizeof(int*) * x)))
		return (NULL);
	while (x_counter < x)
	{
		if (!(heatmap[x_counter] = ft_memalloc(sizeof(int) * y)))////leaks, fix
			return (NULL);
		x_counter++;
	}
	return (heatmap);
}