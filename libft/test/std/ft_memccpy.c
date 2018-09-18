#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *msg = "This is the string: not copied";
	char buffer[80];

    memset(buffer, '\0', 80);
    printf("%d\n", (char) memccpy(buffer, msg, ':', 80));
    printf("%s\n", buffer);
}