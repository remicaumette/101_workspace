#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s = ft_strjoin("hello", " world");
	int code = strcmp(s, "hello world");
	free(s);
	return (code);
}
