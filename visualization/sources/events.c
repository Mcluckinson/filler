/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:05:55 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 07:20:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void	key_events(t_env *env, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_SPACE)
		parse(env);
}

// void	mouse_events(t_env *env, SDL_Event event)
// {
	
// }
