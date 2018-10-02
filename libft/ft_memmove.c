/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:37:33 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 18:34:42 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	char	tmp[len];

	s1 = (char *)dst;
	s2 = (char *)src;
	ft_memcpy(tmp, s2, len);
	ft_memcpy(s1, tmp, len);
	return (dst);
}
