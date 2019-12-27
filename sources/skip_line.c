/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 21:12:54 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/27 21:14:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

bool		skip_line(int nbr)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < nbr)
	{
		if (!get_next_line(0, &line))
			return (false);
		ft_strdel(&line);
	}
	return (true);
}