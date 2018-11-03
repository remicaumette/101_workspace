/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:26:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 02:45:14 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char		*path_join(char *path, char *filename)
{
	char	*str;
	char	*tmp;

	if (!path)
		return (ft_strdup(filename));
	if (*(path + ft_strlen(path) - 1) == '/')
		return (ft_strjoin(path, filename));
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

void		ft_strarr_sort(char **arr, int reverse)
{
	int		i;
	int		j;
	char	*buf;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		i++;
	while (--i > 0 && (j = -1))
		while (++j < i)
			if ((ft_strcmp(arr[i], arr[j]) < 0 && !reverse) ||
				(ft_strcmp(arr[i], arr[j]) > 0 && reverse))
			{
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
}

char		get_file_type(struct stat *stats)
{
	if (S_ISREG(stats->st_mode))
		return ('-');
	if (S_ISDIR(stats->st_mode))
		return ('d');
	if (S_ISBLK(stats->st_mode))
		return ('b');
	if (S_ISCHR(stats->st_mode))
		return ('c');
	if (S_ISLNK(stats->st_mode))
		return ('l');
	if (S_ISFIFO(stats->st_mode))
		return ('p');
	if (S_ISSOCK(stats->st_mode))
		return ('s');
	return ('?');
}

t_fileinfo	*fileinfo_last(t_fileinfo *node)
{
	if (!node->left)
		return (node);
	return (fileinfo_last(node->left));
}
