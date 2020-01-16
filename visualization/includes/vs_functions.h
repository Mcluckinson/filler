/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 06:26:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "vs_filler.h"

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
void			init_sdl(t_sdl *sdl);
t_env			*init_env(void);

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
