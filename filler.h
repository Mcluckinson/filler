/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyuriko <cyuriko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:37:46 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/26 19:08:05 by cyuriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLER_H
# define FILLER_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# define UNIQ_BPP 4
# define MAP_H 1000
# define MAP_W 1000

typedef struct 		s_piece
{
	int 			x;////actually its height
	int 			y;////actually its width oh god why
	char			**piece;////the piece itself
	int 			**piece_map;/////piece_map_for_heat_map
	int 			x_pos;/////position
	int 			y_pos;/////position
}					t_piece;

typedef struct 		s_map
{
	int 			x;////actually its height
	int 			y;////actually its width oh god why
	char			**map;////the map itself
	int 			**heatmap;////transformed heatmap
}					t_map;

typedef struct 		s_data
{
	int 			p_num;
	char 			symbol;
	t_map			*map;
	t_piece			*piece;
}					t_data;



/**
 * all sort of freeshing
 */

int 	free_split_int(int **split);




#endif