/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 01:56:51 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 03:09:12 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

char	*path_join(char *path, char *filename)
{
	char	*str;
	char	*tmp;

	if (!path || !*path)
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

char	*file_readlink(char *path, struct stat *stats)
{
	char	buf[1024];
	int		size;
	char	*tmp;

	if (S_ISLNK(stats->st_mode))
	{
		size = readlink(path, buf, 1024);
		if (!(tmp = ft_strnew(size)))
			return (NULL);
		ft_strncpy(tmp, buf, size);
		return (tmp);
	}
	return (NULL);
}

void	stradd_formatted_left(char *str, char *content, int *cursor,
	int width)
{
	int	i;
	int	len;

	len = ft_strlen(content);
	i = -1;
	if (width != -1)
		while (++i < (width - len))
			str[(*cursor)++] = ' ';
	while (*content)
		str[(*cursor)++] = *content++;
}

void	stradd_formatted_right(char *str, char *content, int *cursor,
	int width)
{
	int	i;
	int	len;

	len = ft_strlen(content);
	i = -1;
	while (*content)
		str[(*cursor)++] = *content++;
	if (width != -1)
		while (++i < (width - len))
			str[(*cursor)++] = ' ';
}

char	file_type(struct stat *stats)
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
