/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 01:53:49 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 02:24:25 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "filler.h"

typedef enum		e_free_code
{
	Env,
	Plateau,
	All
}					t_free_code;

typedef struct 		s_plateau
{
	int 			height;
	int 			width;
	char			**map;
	int 			**heat_map;
}					t_plateau;

typedef struct		s_env
{
	char			my_symb;
	char			enemy_symb;
	t_plateau		*plateau;
}					t_env;

#endif
