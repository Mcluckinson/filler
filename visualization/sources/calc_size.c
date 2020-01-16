/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 08:27:29 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 09:15:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

t_math		calc_size(t_env *env)
{
	t_math	math;
	int		plateau_height;
	int		plateau_width;

	if (env->plateau->width > env->plateau->height)
		math.cell_shift = (env->sdl->sur->w * 0.9) / env->plateau->width;
	else
		math.cell_shift = (env->sdl->sur->h * 0.9) / env->plateau->height;
	plateau_height = math.cell_shift * env->plateau->height;
	plateau_width = math.cell_shift * env->plateau->width;
	math.cell_size = math.cell_shift * 85 / 100;
	// math.cell_size = math.cell_shift;
	math.start_y = (env->sdl->sur->h - 50 - plateau_height
						+ (math.cell_shift - math.cell_size)) / 2;
	math.start_x = (env->sdl->sur->w - 500 - plateau_width
						+ (math.cell_shift - math.cell_size)) / 2;
	return (math);
}
