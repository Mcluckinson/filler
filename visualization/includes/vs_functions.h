/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_functions.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:50:17 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 01:55:23 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "vs_filler.h"

/*
**	init.c
*/
void			init_sdl(t_sdl *sdl);
t_env			*init_env(void);

/*
**	ft_exit.c
*/
void			ft_exit(char *error_text);

/*
**	sdl_loop.c
*/
void				sdl_loop(SDL_Window *win);

#endif
