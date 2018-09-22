#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = ft_strtrim(" \t\nhello \t\nworld \t\n");
	int code = strcmp(s, "hello \t\nworld");
	free(s);
	return (code);
}
