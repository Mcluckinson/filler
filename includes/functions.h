/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 02:57:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "filler.h"

/*
**	init.c
*/
int			**init_heat_map(int height, int width);
char		**init_map(int height);
bool		init_sub_struct(t_env *env);
t_env		*init_env(void);

/*
**	main.c
*/
void		print_in_file(char c, char *str, char **map, int **heat_map, int value);

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
void		ft_free(int code, t_env *env);

#endif
