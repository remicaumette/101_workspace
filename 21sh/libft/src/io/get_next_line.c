/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:01:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/08 11:58:47 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_gnl	*file_add(t_gnl **begin, int fd)
{
	t_gnl	*file;

	if ((file = ft_memalloc(sizeof(t_gnl))) == NULL)
		return (NULL);
	file->fd = fd;
	file->content = NULL;
	file->next = *begin;
	return (*begin = file);
}

static t_gnl	*file_find_or_add(t_gnl **begin, const int fd)
{
	t_gnl	*file;

	file = *begin;
	while (file)
		if (file->fd == fd)
			return (file);
		else
			file = file->next;
	return (file_add(begin, fd));
}

static int		append(t_gnl *file, char *buf)
{
	char	*tmp;

	if (file->content)
	{
		if ((tmp = ft_strjoin(file->content, buf)) == NULL)
			return (0);
		ft_strdel(&(file->content));
	}
	else if ((tmp = ft_strdup(buf)) == NULL)
		return (0);
	file->content = tmp;
	return (1);
}

static int		has_next_line(t_gnl *file, char *delimiter,
	char **line, int readed)
{
	char	*tmp;

	if (readed == -1)
		return (-1);
	if (!file->content || (delimiter == NULL && file->content[0] == 0))
	{
		ft_strdel(&(file->content));
		ft_memdel((void **)&file);
		return (0);
	}
	if (!delimiter)
	{
		if ((*line = ft_strdup(file->content)) == NULL)
			return (-1);
		ft_strdel(&(file->content));
		return (1);
	}
	if ((*line = ft_strsub(file->content, 0, delimiter - file->content))
		== NULL)
		return (-1);
	if ((tmp = ft_strdup(delimiter + 1)) == NULL)
		return (-1);
	ft_strdel(&(file->content));
	file->content = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*files = NULL;
	t_gnl			*curr;
	char			buf[BUFF_SIZE + 1];
	int				readed;
	char			*delimiter;

	if (fd < 0 || !line || read(fd, buf, 0) == -1 ||
		(curr = file_find_or_add(&files, fd)) == NULL)
		return (-1);
	while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[readed] = 0;
		if (append(curr, buf) == 0)
			return (-1);
		if ((delimiter = ft_strchr(curr->content, '\n')) != NULL)
			return (has_next_line(curr, delimiter, line, readed));
	}
	return (has_next_line(curr, curr->content ?
		ft_strchr(curr->content, '\n') : NULL, line, readed));
}
