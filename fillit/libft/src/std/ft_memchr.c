/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:35:22 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:05:16 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			curr;

	str = (unsigned char *)s;
	curr = 0;
	while (curr < n)
		if (str[curr] == (unsigned char)c)
			return (str + curr);
		else
			curr++;
	return (NULL);
}
