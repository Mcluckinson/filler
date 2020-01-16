/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 17:03:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "vs_filler.h"

void	print_in_file(char c, char *str, int **map); //delete

/*
**	calc_size.c
*/
void			calc_size(t_env *env);

/*
**	change_music.c
*/
void			change_music(int game_mode, Mix_Music **music);

/*
**	events.c
*/
void			key_events(t_env *env, SDL_Event event);
void			mouse_events(t_env *env, SDL_Event event);

/*
**	init.c
*/
char			**init_map(const int height);
t_plateau		*init_plateau(void);
t_env			*init_env(void);

/*
**	init_sdl.c
*/
void			init_sdl(int game_mode, t_sdl *sdl);

/*
**	ft_exit.c
*/
void			ft_exit(const char *error_text);

/*
**	main_loop.c
*/
void			main_loop(t_env *env);

/*
**	parse.c
*/
void			parse(t_env *env);

/*
**	render.c
*/
void			render(t_env *env);

#endif
