/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 02:45:11 by sleonia          ###   ########.fr       */
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
t_plateau	*init_plateau(void);
t_env		*init_env(void);

/*
**	main.c
*/
void		print_in_file(char c, char *str, char **map, int **heat_map, int value);

/*
**	parse_plateau.c
*/
bool		parse_plateau(t_env *env);
bool		parse_plateau_size(t_env *env);

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
