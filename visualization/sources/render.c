/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:02:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 03:34:26 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static void	draw_background(t_sdl *sdl)
{
	SDL_FillRect(sdl->sur, NULL,
				SDL_MapRGB(sdl->sur->format, 230, 255, 255));
}


void		render(t_env *env)
{
	draw_background(env->sdl);
	// draw_map();
}
