/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:26:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 18:53:08 by rcaumett    ###    #+. /#+    ###.fr     */
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

void	ft_strarr_sort(char **arr, int reverse)
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

void	append_file_color(t_fileinfo *file, char *s)
{
	if (S_ISDIR(file->stats->st_mode))
		ft_strcat(s, "\033[01;34");
	else if (S_ISLNK(file->stats->st_mode))
		ft_strcat(s, "\033[01;36");
	else if (S_ISBLK(file->stats->st_mode))
		ft_strcat(s, "\033[01;33");
}
