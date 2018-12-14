/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:41:11 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:06:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;
	int	curr;

	length = ft_strlen(s);
	curr = length + 1;
	while (curr--)
		if (s[curr] == c)
			return ((char *)s + curr);
	return (NULL);
}
