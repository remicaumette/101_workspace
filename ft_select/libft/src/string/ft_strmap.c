/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:40:33 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 14:48:31 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if (!s || !f || (tmp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	i = 0;
	while (*s)
		tmp[i++] = f(*s++);
	return (tmp);
}
