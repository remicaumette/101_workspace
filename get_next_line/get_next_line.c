/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:01:39 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 19:10:58 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*file_add(t_file **begin, int fd)
{
	t_file	*file;

	if ((file = (t_file *)ft_memalloc(sizeof(t_file))) == NULL)
		return (NULL);
	file->fd = fd;
	file->size = 0;
	file->content = NULL;
	file->next = *begin;
	return (*begin = file);
}

static t_file	*file_find_or_add(t_file **begin, const int fd)
{
	t_file	*file;

	file = *begin;
	while (file)
		if (file->fd == fd)
			return (file);
		else
			file = file->next;
	return (file_add(begin, fd));
}

static int		append(t_file *file, char *s2, int readed)
{
	char	*new;
	int		i;

	if ((new = ft_memalloc(file->size + readed)) == NULL)
		return (0);
	if (file->content)
		ft_memcpy(new, file->content, file->size);
	i = -1;
	while (++i < readed)
		new[i + file->size] = s2[i];
	file->size += i;
	if (file->content)
		ft_strdel(&(file->content));
	file->content = new;
	return (1);
}

static int		get_line(t_file *file, char **line, int readed, int end)
{
	char	*tmp;
	int		i;

	if (readed == -1 || file->size <= 0)
		return (readed == -1 ? -1 : 0);
	i = -1;
	if ((*line = ft_strnew(end)) == NULL)
		return (-1);
	ft_memcpy(*line, file->content, end);
	if ((tmp = ft_strsub(file->content, end + 1, file->size)) == NULL)
		return (-1);
	file->size -= (end + 1);
	ft_strdel(&(file->content));
	file->content = tmp;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*files = NULL;
	t_file			*curr;
	char			buf[BUFF_SIZE];
	int				readed;
	int				end;

	end = -1;
	if (read(fd, buf, 0) == -1 ||
		(curr = file_find_or_add(&files, fd)) == NULL)
		return (-1);
	while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (append(curr, buf, readed) == 0)
			return (-1);
		while (++end < curr->size)
			if (curr->content[end] == '\n')
				return (get_line(curr, line, readed, end));
	}
	while (++end < curr->size)
		if (curr->content[end] == '\n')
			return (get_line(curr, line, readed, end));
	return (get_line(curr, line, readed, end));
}
