/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/28 00:35:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int 	main()
{
	t_env	*env;

	if (!(env = init_env()))
		return (int_error(ERROR_MALLOC));
	if (!(parse_player(env)))
		return (int_error(ERROR_INPUT));
	if (!(parse_plateau(env)))
		return (int_error(ERROR_INPUT));
	read_map(env);
	init_heatmap(env);
	
	remove("sleonia.txt");
	int fd = open("sleonia.txt", O_CREAT);
	system("chmod 777 sleonia.txt");
	fd = open("sleonia.txt", O_WRONLY);

	for (size_t i = 0; i < env->map->height; i++)
	{
		for (size_t k = 0; k < env->map->width; k++)
		{
			ft_putnbr_fd(env->map->heatmap[i][k], fd);
			ft_putchar_fd(' ', fd);
		}		
		ft_putchar_fd('\n', fd);
	}
	return (0);
}