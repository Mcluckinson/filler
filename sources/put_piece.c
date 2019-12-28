// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   put_piece.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/12/28 05:30:04 by sleonia           #+#    #+#             */
// /*   Updated: 2019/12/28 06:03:46 by sleonia          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "filler.h"

// static int	calc_sum(t_plateau *plateau, t_piece *piece, int y, int x)
// {
// 	int	j;
// 	int	i;
// 	int	sum;
// 	int	player_counter;

// 	sum = 0;
// 	player_counter = 0;
// 	j = -1;
// 	while (++j < piece->height)
// 	{
// 		i = -1;
// 		while (++i < piece->width)
// 			if (piece->map[j][i] == '*')
// 			{
// 				if ((y + j) < 0 || (y + j) >= plateau->height
// 					|| (x + i) < 0 || (x + i) >= plateau->width
// 					|| plateau->heat_map[y + j][x + i] == ENEMY)
// 					return (-1);
// 				if (plateau->heat_map[y + j][x + i] == PLAYER)
// 					player_counter++;
// 				sum += plateau->heat_map[y + j][x + i];
// 			}
// 	}
// 	return ((player_counter == 1) ? sum : -1);
// }

// void		calc_coords(t_plateau *plateau, t_piece *piece, t_filler *filler)
// {
// 	int	j;
// 	int	i;
// 	int	sum;
// 	int	min_sum;

// 	min_sum = FT_INT_MAX;
// 	j = -(piece->height);
// 	while (j < plateau->height + piece->height)
// 	{
// 		i = -(piece->width);
// 		while (i < plateau->width + piece->width)
// 		{
// 			sum = calc_sum(plateau, piece, j, i);
// 			if (sum != -1 && sum < min_sum)
// 			{
// 				filler->y = j;
// 				filler->x = i;
// 				min_sum = sum;
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// }

// // bool		put_piece(t_env *env)
// // {
// // 	int		h;
// // 	int		w;

// // 	h = -1;
// // 	w = -1;
// // 	while (++h < piece->height)
// // 	{
// // 		w = -1;
// // 		while (++w < piece->width)
// // 		{
// // 			if (piece->piece[h][w] == '*')
// // 				piece->piece_map[h][w] = 1;
// // 		}
// // 	}
	
// // 	return (true);
// // }
