#include <stdio.h>

int		ft_strlen(char *str);

int		main(int argc, char **argv) {
	if (argc >= 2)
		printf("length: %d\n", ft_strlen(argv[1]));
}
