/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:37:33 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 19:45:41 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (s2 >= s1)
		ft_memcpy(s1, s2, len);
	else
	{
		s1 += len;
		s2 += len;
		while (s1 > (char *)dst)
			*--s1 = *--s2;
	}
	return (dst);
}
