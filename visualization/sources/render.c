/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:02:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 09:17:55 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static void		draw_background(t_sdl *sdl)
{
	SDL_Rect rect;

	rect.h = sdl->sur->h;
	rect.w = sdl->sur->w;
	rect.y = 0;
	rect.x = 0;
	SDL_FillRect(sdl->sur, &rect,
				SDL_MapRGB(sdl->sur->format, 224, 224, 224));
}

static void		draw_map(t_env *env)
{
	t_math		math;
	SDL_Rect	rect;
	int			x;
	int			y;

	y = -1;
	math = calc_size(env);
	rect.w = math.cell_size;
	rect.h = math.cell_size;
	while (++y < env->plateau->height)
	{
		x = -1;
		while (++x < env->plateau->width)
		{
			rect.x = math.start_x + x * math.cell_shift;
			rect.y = math.start_y + y * math.cell_shift;
			if (env->plateau->map[y][x] == '.')
				SDL_FillRect(env->sdl->sur, &rect, SDL_MapRGB(env->sdl->sur->format, 173, 220, 244));
			else if (ft_toupper(env->plateau->map[y][x]) == 'O')
				SDL_FillRect(env->sdl->sur, &rect, SDL_MapRGB(env->sdl->sur->format, 255, 0, 0));
			else if (ft_toupper(env->plateau->map[y][x]) == 'X')
				SDL_FillRect(env->sdl->sur, &rect, SDL_MapRGB(env->sdl->sur->format, 0, 0, 255));
		}
	}
}

void		render(t_env *env)
{
	draw_background(env->sdl);
	draw_map(env);
}
