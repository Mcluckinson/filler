/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 04:33:39 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/16 09:25:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vs_filler.h"

extern int fd;

static void		parse_plateau_size(char *line, t_plateau *plateau)
{
	char		**split;

	if (!(split = ft_strsplit(line, ' ')))
		ft_exit(ERROR_STRSPLIT);
	plateau->height = ft_atoi(split[1]);
	plateau->width = ft_atoi(split[2]);
	ft_destroy_string_arr(split);
}

static void		check_line(const char *line)
{
	int			i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '.'
			|| ft_toupper(line[i]) == 'O'
			|| ft_toupper(line[i]) == 'X')
			continue ;
		else
			ft_exit(ERROR_INPUT);
	}
}

static void		parse_plateau(t_plateau *plateau)
{
	int			i;
	char		*line;
	char		**split;

	if (get_next_line(0, &line) != 1)
		ft_exit("ERROR_GNL");
	ft_strdel(&line);
	i = -1;
	plateau->map = init_map(plateau->height + 1);
	while (++i < plateau->height)
	{
		if (get_next_line(0, &line) != 1)
			ft_exit("ERROR_GNL");
		if (!(split = ft_strsplit(line, ' ')))
			ft_exit(ERROR_STRSPLIT);
		if (!(plateau->map[i] = ft_strdup(split[1])))
			ft_exit("ERROR_STRDUP");
		check_line((const char *)plateau->map[i]);
		ft_strdel(&line);
		ft_destroy_string_arr(split);
	}
}

static void		add_to_list(t_env *env, t_plateau *plateau)
{
	if (!env->plateau)
		env->plateau = plateau;
	else
	{
		while (env->plateau)
		{
			if (!env->plateau->next)
			{
				plateau->prev = env->plateau;
				env->plateau->next = plateau;
			}
			env->plateau = env->plateau->next;
		}
	}
}

void			parse(t_env *env)
{
	char		*line;
	t_plateau	*plateau;

	plateau = NULL;
	while (!plateau && get_next_line(0, &line) == 1)
	{
		if (ft_strstr(line, "Plateau"))
		{
			plateau = init_plateau();
			parse_plateau_size(line, plateau);
			parse_plateau(plateau);
			add_to_list(env, plateau);
		}
		ft_strdel(&line);
	}
}
