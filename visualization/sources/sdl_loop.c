/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:44:00 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 01:44:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void				sdl_loop(SDL_Window *win)
{
	SDL_Event		event;

	while (true)
	{
		SDL_WaitEvent(&event);
		if (SDL_QUIT == event.type || SDLK_ESCAPE == event.key.keysym.sym)
			break ;
		SDL_UpdateWindowSurface(win);
	}
	SDL_DestroyWindow(win);
	SDL_Quit();
}