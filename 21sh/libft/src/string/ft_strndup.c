/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 21:18:59 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 21:18:59 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*out;
	char		*tmp;
	size_t		len_max;

	len_max = ft_strlen(s1);
	if (len_max > n)
		len_max = n;
	if ((out = (char *)malloc(sizeof(char) * (len_max + 1))) == NULL)
		return (NULL);
	tmp = out;
	while (*s1 && n)
	{
		*out = *s1;
		out++;
		s1++;
		n--;
	}
	*out = '\0';
	return (tmp);
}
