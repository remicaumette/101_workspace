/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:41:33 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 15:06:13 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	int	offset;
	int	limit;

	if (!s)
		return (NULL);
	offset = 0;
	limit = ft_strlen(s) - 1;
	while (s[offset] && is_whitespace(s[offset]))
		offset++;
	while (limit > offset && is_whitespace(s[limit]))
		limit--;
	return (ft_strsub(s, offset, limit - offset + 1));
}
