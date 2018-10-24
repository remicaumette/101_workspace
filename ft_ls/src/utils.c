/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:26:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:15:57 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_join(char *path, char *filename)
{
	char	*str;
	char	*tmp;

	if (!path)
		return (ft_strdup(filename));
	if (!(str = ft_strnew(ft_strlen(path) + ft_strlen(filename) + 1)))
		return (NULL);
	tmp = str;
	while (*path)
		*tmp++ = *path++;
	*tmp++ = '/';
	while (*filename)
		*tmp++ = *filename++;
	return (str);
}

char	**strarr_add(char **arr, char *elem)
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
	tmp [i] = NULL;
	free(arr);
	return (tmp);
}

void	strarr_sort(char **arr, int reverse)
{
	int		i;
	int		j;
	char	*buf;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		i++;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if ((ft_strcmp(arr[i], arr[j]) < 0 && !reverse) ||
				(ft_strcmp(arr[i], arr[j]) > 0 && reverse))
			{
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
		}
	}
}

void			strarr_del(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		ft_strdel(&arr[i]);
	free(arr);
}
