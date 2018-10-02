#include "libft.h"
#include "get_next_line.h"

static int	append(char **s1, char *s2)
{
	char *new;

	if (*s1)
	{
		new = ft_strjoin(*s1, s2);
		//if (s1 && *s1)
		//	free(*s1);
	}
	else
		new = ft_strdup(s2);
	if (new == NULL)
		return (0);
	*s1 = new;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*curr = NULL;
	char		buf[BUFF_SIZE + 1];
	int			readed;
	char		*tmp;

	while ((readed = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[BUFF_SIZE] = 0;
		if (append(&curr, buf) == 0)
			return (-1);
		if ((tmp = ft_strchr(curr, '\n')) != NULL)
		{
			*line = ft_strsub(curr, 0, tmp - curr);
			curr = tmp + 1;
			return (readed == BUFF_SIZE);
		}
	}
	return (readed);
}

#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *str = NULL;
		int fd = open(argv[1], O_RDONLY);
		int i;
		while ((i = get_next_line(fd, &str)) != -1)
		{
			printf("%d\n", i);
			printf("%s\n", str);
			if (i == 0)
				break;
		}
	}
}
