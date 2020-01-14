/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 06:23:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "filler.h"

/*
**	math_heatmap.c
*/
bool		math_heatmap(t_env *env);

/*
**	init.c
*/
int			**init_heatmap(int height, int width);
char		**init_map(int height);
bool		init_sub_struct(t_env *env);
t_env		*init_env(void);

/*
**	main.c
*/
void		print_in_file(char c, char *str, char **map, int **heatmap, int h, int w, int value);

/*
**	parse_piece.c
*/
bool		parse_piece(t_env *env);

/*
**	parse_plateau.c
*/
bool		parse_plateau(t_env *env);

/*
**	parse_player.c
*/
bool		parse_player(t_env *env);

/*
**	utilits.c
*/
void		print_coords(int x, int y);
int			ft_free(t_env *env);

#endif
