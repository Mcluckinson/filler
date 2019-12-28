/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 06:18:00 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 07:51:58 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			**get_new_map(int height, int width)
{
	int		i;
	int		**new_piece_map;

	i = -1;
	if (height == 0 || width == 0)
		return (NULL);
	new_piece_map = (int **)ft_memalloc(sizeof(int *) * height); //protect
	while (++i < height)
		new_piece_map[i] = (int *)ft_memalloc(sizeof(int) * width); //protect
	return (new_piece_map);
}

void			new_cropped_map(t_piece *piece)
{
	int			i;
	int			k;
	int			width;
	int			height;
	int			**new_piece_map;

	piece->height = piece->down - piece->up + 1;
	piece->width = piece->rightmost - piece->leftmost + 1;
	if (!(new_piece_map = get_new_map(piece->height, piece->width)))
		return ; //protect
	i = piece->up - 1;
	while (i++ < piece->down)
	{
		k = piece->leftmost - 1;
		while (k++ < piece->rightmost)
		{
			if (piece->piece_map[i][k] == 1)
			{
				piece->piece_map[i][k] = 0;
				new_piece_map[i - piece->up][k - piece->leftmost] = 1;
			}
			// piece[]
		}
	}
	// ft_destroy_int_arr(piece->piece_map, piece->height);
	piece->piece_map = new_piece_map;
}
