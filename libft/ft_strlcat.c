/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:40:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 16:59:45 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	offset;
	char	*ptr;

	offset = ft_strlen(dst);
	if (dstsize <= offset + ft_strlen(src))
		return (dstsize + 1);
	ptr = dst;
	while (*src)
		*(ptr++ + offset) = *src++;
	return (ft_strlen(dst));
}
