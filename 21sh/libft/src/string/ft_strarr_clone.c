/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_clone.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/15 13:34:20 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 13:34:29 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_clone(char **arr)
{
	int		i;
	char	**tmp;

	i = -1;
	tmp = NULL;
	while (arr && arr[++i])
		if (!(tmp = ft_strarr_add(tmp, arr[i])))
			return (NULL);
	return (tmp);
}
