/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:44:00 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 09:06:32 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void				main_loop(t_env *env)
{
	SDL_Event		event;

	while (!env->is_pause)
	{
		render(env);
		SDL_WaitEvent(&event);
		if (SDL_QUIT == event.type || SDLK_ESCAPE == event.key.keysym.sym)
			break ;
		if (event.type == SDL_KEYDOWN)
			key_events(env, event);
		// else if (event.type == SDL_MOUSEBUTTONDOWN)
			// mouse_events(env, event);
		SDL_UpdateWindowSurface(env->sdl->win);
		SDL_Delay(1000 / 60);
	}
	SDL_DestroyWindow(env->sdl->win);
	SDL_Quit();
}
