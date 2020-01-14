/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:21:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 06:03:26 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(int x, int y)
{
	ft_putnbr_fd(x, 0);
	ft_putchar_fd(' ', 0);
	ft_putnbr_fd(y, 0);
	ft_putchar_fd('\n', 0);
}

int		ft_free(t_env *env)
{
	ft_destroy_string_arr(env->piece->map);
	ft_destroy_int_arr(env->piece->heatmap, env->piece->height);
	ft_memdel((void *)&env->piece);
	ft_destroy_string_arr(env->plateau->map);
	ft_destroy_int_arr(env->plateau->heatmap, env->plateau->height);
	ft_memdel((void *)&env->plateau);
	ft_memdel((void *)&env);
	return (1);
}
