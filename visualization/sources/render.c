/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 02:02:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 16:49:23 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

static void			render_background(t_sdl *sdl)
{
	SDL_Rect rect;

	rect.h = sdl->sur->h;
	rect.w = sdl->sur->w;
	rect.y = 0;
	rect.x = 0;
	SDL_FillRect(sdl->sur, &rect,
				SDL_MapRGB(sdl->sur->format, 224, 224, 224));
}

static void			render_map(t_env *env)
{
	SDL_Rect		rect;
	int				x;
	int				y;

	y = -1;
	calc_size(env);
	rect.w = env->math->cell_size;
	rect.h = env->math->cell_size;
	while (++y < env->plateau->height)
	{
		x = -1;
		while (++x < env->plateau->width)
		{
			rect.x = env->math->start_x + x * env->math->cell_shift;
			rect.y = env->math->start_y + y * env->math->cell_shift;
			if (env->plateau->map[y][x] == '.')
			{
				SDL_FillRect(env->sdl->sur, &rect, SDL_MapRGB(env->sdl->sur->format, 173, 220, 244));
			}
			else if (ft_toupper(env->plateau->map[y][x]) == 'O')
			{
				SDL_FillRect(env->sdl->sur, &rect, SDL_MapRGB(env->sdl->sur->format, 255, 0, 0));
				env->math->enemy_score++;
			}
			else if (ft_toupper(env->plateau->map[y][x]) == 'X')
			{
				SDL_FillRect(env->sdl->sur, &rect, SDL_MapRGB(env->sdl->sur->format, 0, 0, 255));
				env->math->my_score++;
			}
		}
	}
}

static void		render_score(t_env *env)
{
	SDL_Rect	rect;
	int			n_digits;
	int			sum_score;
	float		percent;

	sum_score = env->math->my_score + env->math->enemy_score;
	n_digits = floor(log10(abs(sum_score))) + 1;
	
}

void			render(t_env *env)
{
	render_background(env->sdl);
	render_map(env);
	render_score(env);
}
