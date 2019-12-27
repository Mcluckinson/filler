/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:29:07 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/25 11:06:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H
# include "libft.h"

/*
**	Function`s to some for work with memory
*/
void				ft_bzero(void *s, size_t n);

/*
**	Free array of pointer to pointer to int
*/
void				ft_destroy_int_arr(int **arr, int i);

/*
**	Free array of pointer to pointer to char
*/
void				ft_destroy_string_arr(char **arr);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

/*
**	Allocated memory and if malloc return NULL do exit
*/
void				*ft_safe_malloc(size_t size);

#endif
