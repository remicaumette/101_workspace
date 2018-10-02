/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:41:17 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 18:32:30 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	arr_size(char const *s, char c)
{
	int	i;
	int	locked;
	int	size;

	i = -1;
	locked = 1;
	size = 1;
	while (s[++i])
		if (s[i] == c)
			locked = 1;
		else if (s[i] != c && locked && ++size)
			locked = 0;
	return (size);
}

static int	str_size(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**v;
	int		locked;
	int		index;
	int		curr;

	if ((v = (char **)ft_memalloc(sizeof(*v) * arr_size(s, c))) == NULL)
		return (NULL);
	locked = 1;
	index = 0;
	curr = -1;
	while (s[++curr])
		if (s[curr] == c)
			locked = 1;
		else if (s[curr] != c && locked)
		{
			v[index] = ft_strsub(s, curr, str_size(s + curr, c));
			if (v[index++] == NULL)
				return (NULL);
			locked = 0;
		}
	v[index] = 0;
	return (v);
}
