/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:10:47 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 14:11:03 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*s;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if ((s = (char *)malloc(sizeof(*s) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*src)
		s[i++] = *src++;
	s[i] = 0;
	return (s);
}
