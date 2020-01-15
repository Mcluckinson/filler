/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:46:47 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 01:52:54 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void			init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		ft_exit("SDL_Init");
	if (!(sdl->win = SDL_CreateWindow("RT",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									WIDTH, HEIGHT,
									SDL_WINDOW_SHOWN)))
		ft_exit("SDL_CreateWindow");
	if (!(sdl->sur = SDL_GetWindowSurface(sdl->win)))
		ft_exit("SDL_GetWindowSurface");
}

t_env			*init_env(void)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_exit(ERROR_MALLOC);
	if (!(env->sdl = (t_sdl *)malloc(sizeof(t_sdl))))
		ft_exit(ERROR_MALLOC);
	return (env);
}
