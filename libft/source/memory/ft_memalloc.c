/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 07:29:30 by sleonia           #+#    #+#             */
/*   Updated: 2020/01/14 04:53:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!(mem = (void *)malloc(size)))
		ft_exit(ERROR_MALLOC);
	ft_bzero(mem, size);
	return (mem);
}
