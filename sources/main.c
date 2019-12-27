/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/27 21:06:26 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	main()
{
	t_env	*env;

	remove("sleonia.txt");
	int fd = open("sleonia.txt", O_CREAT);
	system("chmod 777 sleonia.txt");
	fd = open("sleonia.txt", O_WRONLY);
	if (!(env = init_env()))
		return (int_error(ERROR_MALLOC));
	if (!(parse_player(env)))
		return (int_error(ERROR_INPUT));
	if (!(parse_plateau(env)))
		return (int_error(ERROR_INPUT));
	// ft_strdel(&line);
	
	ft_putchar_fd(env->player_symbol, fd);
	ft_putchar_fd('\n', fd);
	ft_putchar_fd(env->opponent_symbol, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(env->map->height, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(env->map->width, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd(line, fd);
	return (0);
}