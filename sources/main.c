/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/14 02:26:06 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int fd;

void	open_file()
{
	remove("sleonia.txt");
	fd = open("sleonia.txt", O_CREAT);
	system("chmod 777 sleonia.txt");
	fd = open("sleonia.txt", O_WRONLY);
}

void	print_in_file(char c, char *str, int value)
{
	if (c)
	{
		ft_putchar_fd(c, fd);
		ft_putchar_fd('\n', fd);
	}
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putchar_fd('\n', fd);
	}
	if (value != -1)
	{
		ft_putnbr_fd(value, fd);
		ft_putchar_fd('\n', fd);
	}
}

int 	main()
{
	t_env	*env;

	open_file();
	//
	if (!(env = init_env()))
		return (int_error(ERROR_MALLOC));
	if (!parse_player(env))
	{
		ft_free(Env, env);
		return (int_error(ERROR_INPUT));
	}
	while (true)
	{
		if (!(env->plateau = init_plateau()))
			return (int_error(ERROR_INPUT));
		if (!parse_plateau_size(env))
			return (int_error(ERROR_INPUT));
		if (!(env->plateau->heat_map = init_heat_map(env->plateau->height, env->plateau->width)))
			return (int_error(ERROR_INPUT));

		char	*line;
		if (get_next_line(0, &line) != 1)
			return (false);
		print_in_file('\0', line, -1);
		if (get_next_line(0, &line) != 1)
			return (false);
		print_in_file('\0', line, -1);
		if (get_next_line(0, &line) != 1)
			return (false);
		print_in_file('\0', line, -1);
		if (get_next_line(0, &line) != 1)
			return (false);
		print_in_file('\0', line, -1);
		if (get_next_line(0, &line) != 1)
			return (false);
		print_in_file('\0', line, -1);
		break ;
	}
	return (0);
}
	// if (get_next_line(0, &line) != 1)
		// return (false);
	// print_in_file('\0', line, -1);
