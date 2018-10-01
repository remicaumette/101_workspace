/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:41:30 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 15:07:01 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*tmp;

	i = -1;
	if ((tmp = ft_strnew(len)) == NULL)
		return (NULL);
	while (++i < len)
		tmp[i] = s[start + i];
	return (tmp);
}
