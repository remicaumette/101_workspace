/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:40:46 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 16:26:34 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t size;

	size = 0;
	while (size < n)
		if (*s1 == *s2)
			s1++ && s2++ && size++;
		else
			return ((unsigned char)*s1 - (unsigned char)*s2);
	return (0);
}
