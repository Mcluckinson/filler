/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_music.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:58:01 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 16:57:30 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void			change_music(int game_mode, Mix_Music **music)
{
	Mix_PauseMusic();
	if (game_mode == Pixel)
		Mix_PlayMusic(music[0], 10);
	else if (game_mode == Gachi)
		Mix_PlayMusic(music[1], 10);
}
