/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:41:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:06:46 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;

	length = ft_strlen(s2);
	j = -1;
	while (++j < len)
	{
		i = 0;
		while (s2[i] && j + i < len)
		{
			if (s2[i] != s1[j + i])
				break ;
			i++;
		}
		if (i == length)
			return ((char *)s1 + j);
	}
	return (NULL);
}
