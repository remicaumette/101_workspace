#include "libft.h"
#include "get_next_line.h"

static t_file	*file_add(t_file **begin, int fd)
{
	t_file *file;

	if ((file = (t_file *)ft_memalloc(sizeof(t_file))) == NULL)
		return (NULL);
	file->fd = fd;
	file->status = 0;
	file->content = NULL;
	file->next = *begin;
	return (*begin = file);
}

static t_file	*file_find_or_create(t_file **begin, const int fd)
{
	t_file *file;
	
	file = *begin;
	while (file)
		if (file->fd == fd)
			return (file);
		else
			file = file->next;
	return (file_add(begin, fd));
}
// free impossible car deplacement ptr
static int		append(char **s1, char *s2)
{
	char *new;

	if (*s1)
		new = ft_strjoin(*s1, s2);
	else
		new = ft_strdup(s2);
	if (new == NULL)
		return (0);
	*s1 = new;
	return (1);
}
#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	static char	*content = NULL;
	static int	size = 0;
	char			buf[BUFF_SIZE];
	int				readed;
	char		*tmp;
	int	i;

	i = -1;
	while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
	{
		size += readed;
		if ((tmp = (char *)ft_memalloc(size)) == NULL)
			return (-1);
		if (content)
			ft_strdel(&content);
		content = tmp;
		while (++i < size)
			if (content[i] == '\n')
				break ;
	}
	if (readed == 0 && size <= 0)
		return (0);
	printf("%d\n", i);
	printf("%s\n", content);
	*line = ft_strsub(content, 0, i);
	size -= (i + 1);
	content += (i + 1);
	return (1);
}

/*
0 = lecture terminer donc read < buffsize
1 = ligne lue donc encore a lire
-1 = erreur
*/