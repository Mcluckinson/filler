/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2-119/12/28 03:48:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/28 04:16:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool		parse_piece_size(t_piece *piece)
{
	char	*line;
	char	**split_whitespace;

	if (!(line = ft_get_line()))
		return (false);
	if (!(split_whitespace = ft_strsplit(line, ' ')))
		return (false);	
	piece->height = ft_atoi(split_whitespace[1]); //?
	piece->width = ft_atoi(split_whitespace[2]); //?
	ft_strdel(&line);
	ft_destroy_string_arr(split_whitespace);
	return (true);
}

char		**create_piece_map(int height)
{
	char	**map;

	if (!(map = ft_memalloc(sizeof(char*) * height)))
		return (NULL);
	return (map);
}

bool		fill_piece_map(t_piece *piece)
{
	int		i;
	char	*line;
	char	**split;

	i = -1;
	while (++i < piece->height)
	{
		if (!(line = ft_get_line()))
			return (false);			
		piece->piece[i] = line;
	}
	return (true);
}

static int	**piece_map(int height, int width)
{
	int			h_counter;
	int			**piece_map;

	if (!(piece_map = (int **)ft_memalloc(sizeof(int *) * height)))
		return (NULL);
	h_counter = -1;
	while (++h_counter < height)
	{
		if (!(piece_map[h_counter] = (int *)ft_memalloc(sizeof(int) * width)))
		{
			ft_destroy_int_arr(piece_map, h_counter);
			return (NULL);
		}
	}
	return (piece_map);
}

static bool	cut_and_transform_to_int_piece(t_piece *piece)
{
	int		h;
	int		w;

	h = -1;
	piece->leftmost = piece->width;
	if (!(piece->piece_map = piece_map(piece->height, piece->width)))
		return (false);
	while (++h < piece->height)
	{
		w = -1;
		while (++w < piece->width)
		{
			if (piece->piece[h][w] == '*')
			{
				piece->piece_map[h][w] = 1;
				if (piece->leftmost > w)
					piece->leftmost = w;
				if (piece->up == -1)
					piece->up = h;
				if (piece->down < h)
					piece->down = h;
				if (piece->rightmost < w)
					piece->rightmost = w;
			}
		}
	}
	return (true);
}

bool		parse_piece(t_piece *piece)
{
	if (!(parse_piece_size(piece)))
		return (false);
	if (!(piece->piece = create_piece_map(piece->height)))
		return (false);
	if (!(fill_piece_map(piece)))
		return (false);
	cut_and_transform_to_int_piece(piece);
	return (true);
}
