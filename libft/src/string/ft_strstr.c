/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:41:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:06:59 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int length;

	length = ft_strlen(s2);
	if (!length)
		return ((char *)s1);
	s1--;
	while (*++s1)
	{
		i = -1;
		while (s2[++i])
			if (s2[i] != *(s1 + i))
				break ;
		if (i == length)
			return ((char *)s1);
	}
	return (NULL);
}
