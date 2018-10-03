#include <stdio.h>
#include <fcntl.h>

int	get_next_line(const int fd, char **line);

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		char *str = NULL;
		int fd = open(argv[1], O_RDONLY);
		int i;
		while ((i = get_next_line(fd, &str)) > 0)
			printf("%s\n", str);
	}
}
