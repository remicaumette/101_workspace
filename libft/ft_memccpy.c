/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:35:17 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 16:24:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*ptr;

	if ((ptr = ft_memchr(src, c, n)) != NULL)
		return (ft_memcpy(dst, src, ptr - src + 1));
	ft_memcpy(dst, src, n);
	return (NULL);
}
