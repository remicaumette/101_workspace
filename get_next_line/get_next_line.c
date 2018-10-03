#include "get_next_line.h"
/*
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
}*/
// free impossible car deplacement ptr
static int		append(char **s1, char *s2, int *size, int readed)
{
	char	*new;
	int		i;

	if ((new = ft_memalloc(*size + readed)) == NULL)
		return (0);
	if (s1 && *s1)
		ft_memcpy(new, *s1, *size);
	i = -1;
	while (++i < readed)
		new[i + *size] = s2[i];
	*size += i;
	if (s1 && *s1)
		ft_strdel(s1);
	*s1 = new;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*content = NULL;
	static int	size = 0;
	char		buf[BUFF_SIZE];
	int			readed;
	char		*tmp;
	int			run;
	int	i;

	i = -1;
	run = 1;
	while (run && (readed = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (append(&content, buf, &size, readed) == 0)
			return (-1);
		while (++i < size)
			if (content[i] == '\n')
			{
				run = 0;
				break ;
			}
	}
	if (readed == -1)
		return (-1);
	if (size <= 0)
		return (0);
	if (line && *line)
		ft_strdel(line);
	*line = ft_strsub(content, 0, i);
	tmp = ft_strsub(content, i + 1, size);
	size -= (i + 1);
	ft_strdel(&content);
	content = tmp;
	return (1);
}

/*
0 = lecture terminer donc read < buffsize
1 = ligne lue donc encore a lire
-1 = erreur
*/