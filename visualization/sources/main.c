/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 01:33:07 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 08:14:25 by sleonia          ###   ########.fr       */
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

void	print_in_file(char c, char *str, char **map)
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
}

int			main(int ac, char **av)
{
	t_env	*env;

	open_file();

	env = init_env();
	init_sdl(env->sdl);
	parse(env);
	main_loop(env);
	return (0);
}
