/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 01:21:04 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 01:30:28 by sleonia          ###   ########.fr       */
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

void	ft_free(int free_code, t_env *env)
{
	ft_memdel((void *)&env);
}
