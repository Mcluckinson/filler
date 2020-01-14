/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2020/01/14 06:27:13 by sleonia          ###   ########.fr       */
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

void	print_in_file(char c, char *str, char **map, int **heatmap, int h, int w, int value)
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
	if (map)
	{
		int i = -1;
		while (map[++i])
		{
			ft_putstr_fd(map[i], fd);
			ft_putchar_fd('\n', fd);
		}
	}
	if (heatmap)
	{
		for (size_t i = 0; i < h; i++)
		{
			for (size_t k = 0; k < w; k++)
			{
				ft_putnbr_fd(heatmap[i][k], fd);
				ft_putchar_fd(' ', fd);
			}
			ft_putchar_fd('\n', fd);
		}
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
		return (1);
	if (!parse_player(env))
		return (ft_free(env));
	while (true)
	{
		if (!init_sub_struct(env))
			return (ft_free(env));
		if (!parse_plateau(env))
			return (int_error(ERROR_INPUT));
		if (!(env->plateau->heatmap = init_heatmap(env->plateau->height,
													env->plateau->width)))
			return (ft_free(env));
		if (!parse_piece(env))
			return (ft_free(env));
		print_in_file('\0', NULL, NULL, env->plateau->heatmap, env->plateau->height, env->plateau->width, -1);
		math_heatmap(env);
		print_in_file('\0', NULL, NULL, env->plateau->heatmap, env->plateau->height, env->plateau->width, -1);

		// char	*line;
		// if (get_next_line(0, &line) != 1)
		// 	return (false);
		// print_in_file('\0', line, NULL, NULL, -1);
		break ;
	}
	return (0);
}
