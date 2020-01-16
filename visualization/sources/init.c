/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:46:47 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 06:27:14 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

char			**init_map(const int height)
{
	char		**map;

	if (!(map = (char **)ft_memalloc(sizeof(char *) * height)))
		return (NULL);
	return (map);
}

t_plateau		*init_plateau(void)
{
	t_plateau	*plateau;

	plateau = (t_plateau *)ft_safe_malloc(sizeof(t_plateau));
	plateau->height = 0;
	plateau->width = 0;
	plateau->next = NULL;
	plateau->prev = NULL;
	return (plateau);
}

void			init_sdl(t_sdl *sdl)
{
	SDL_Surface		*sur_icon;
	SDL_Surface		*conv_sur_icon;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("SDL_Init");
	if (!(sdl->win = SDL_CreateWindow("RT",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									WIDTH, HEIGHT,
									SDL_WINDOW_FULLSCREEN_DESKTOP)))
		ft_exit(SDL_GetError());
	if (!(sdl->sur = SDL_GetWindowSurface(sdl->win)))
		ft_exit(SDL_GetError());
	if (!(sur_icon = IMG_Load("./assets/icon.png")))
		ft_exit(SDL_GetError());
	if (!(conv_sur_icon = SDL_ConvertSurface(sur_icon, sdl->sur->format, 0)))
		ft_exit(SDL_GetError());
	SDL_SetWindowIcon(sdl->win, conv_sur_icon);
	SDL_FreeSurface(sur_icon);
	SDL_FreeSurface(conv_sur_icon);
}

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env *)ft_safe_malloc(sizeof(t_env));
	env->sdl = (t_sdl *)ft_safe_malloc(sizeof(t_sdl));
	env->plateau = NULL;
	env->is_pause = false;
	return (env);
}
