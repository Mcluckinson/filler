/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:53:49 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 04:10:55 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "vs_filler.h"

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Surface			*sur;
	SDL_Event			event;
}						t_sdl;

typedef struct			s_plateau
{
	int					height;
	int					width;
	char				**map;
	struct s_plateau	*next;
	struct s_plateau	*prev;
}						t_plateau;

typedef struct			s_env
{
	t_sdl				*sdl;
	t_plateau			*plateau;
	bool				is_pause;
}						t_env;

#endif
