/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:21:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 08:42:43 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coords(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
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
