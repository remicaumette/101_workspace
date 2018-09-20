#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2);

int		main(int argc, char **argv) {
	if (argc >= 3)
		printf("returned: %d expected: %d", ft_strcmp(argv[1], argv[2]), strcmp(argv[1], argv[2]));
}
