/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_add.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 11:41:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 11:41:32 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_add(char **arr, char *elem)
{
	char	**tmp;
	int		len;
	int		i;

	len = 0;
	while (arr && arr[len])
		len++;
	if (!(tmp = ft_memalloc(sizeof(*tmp) * (len + 2))))
		return (NULL);
	i = -1;
	while (++i < len)
		tmp[i] = arr[i];
	tmp[i++] = ft_strdup(elem);
	tmp[i] = NULL;
	ft_memdel((void **)&arr);
	return (tmp);
}
