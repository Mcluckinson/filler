/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:58:01 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 10:59:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

void			change_music(Mix_Music **music)
{
	Mix_PauseMusic();
	if (music_flag_0 == flag)
		Mix_PlayMusic(music[0], 10);
	else if (music_flag_1 == flag)
		Mix_PlayMusic(music[1], 10);
	else if (music_flag_2 == flag)
		Mix_PlayMusic(music[2], 10);
	else if (music_flag_3 == flag)
		Mix_PlayMusic(music[3], 10);
}
