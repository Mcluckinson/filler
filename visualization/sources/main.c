/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:33:07 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 15:11:22 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

int fd;

void	open_file()
{
	remove("./lox.txt");
	fd = open("./lox.txt", O_CREAT);
	system("chmod 777 lox.txt");
	fd = open("./lox.txt", O_WRONLY);
}

void	print_in_file(char c, char *str, int **map)
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
			int k = -1;
			while (map[i][++k])
			{
				ft_putnbr_fd(map[i][k], fd);
				ft_putchar_fd(' ', fd);
			}
			
			ft_putchar_fd('\n', fd);
		}
	}
}

int			main(int ac, char **av)
{
	t_env	*env;

	open_file();

	env = init_env();
	init_sdl(env->game_mode, env->sdl);
	parse(env);
	main_loop(env);
	return (0);
}
