/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:34:49 by cyuriko           #+#    #+#             */
/*   Updated: 2019/12/28 04:39:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

extern int fd;

int 	main()
{
	t_env	*env;
	
	remove("sleonia.txt");
	fd = open("sleonia.txt", O_CREAT);
	system("chmod 777 sleonia.txt");
	fd = open("sleonia.txt", O_WRONLY);

	if (!(env = init_env()))
		return (int_error(ERROR_MALLOC));
	if (!(parse_player(env)))
		return (int_error(ERROR_INPUT));
	if (!(parse_plateau(env)))
		return (int_error(ERROR_INPUT));
	read_map(env);
	init_heatmap(env);
	parse_piece(env->piece);

	for (size_t i = 0; i < env->piece->height; i++)
	{
		for (size_t k = 0; k < env->piece->width; k++)
		{
			ft_putnbr_fd(env->piece->piece_map[i][k], fd);
			// ft_putchar_fd(' ', fd);
		}		
		ft_putchar_fd('\n', fd);
	}
	ft_putnbr_fd(env->piece->height, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(env->piece->width, fd);
	// while (1) ;
	return (0);
}