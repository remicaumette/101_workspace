/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   std.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 13:57:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:57:51 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H
# include <stdlib.h>

void	ft_bzero(void *mem, size_t size);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
#endif