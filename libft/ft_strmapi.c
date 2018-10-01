/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:40:38 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:06:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	if ((tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s && ++i)
		tmp[i - 1] = f(i - 1, *s++);
	return (tmp);
}
