/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:40:41 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 16:40:44 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s1;
	i = 0;
	while (*s1)
		s1++;
	while (s2[i] && i < n)
		*s1++ = s2[i++];
	*s1 = 0;
	return (ptr);
}
