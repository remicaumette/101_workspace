#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *s1 = ft_strdup("hello world");
	char *s2 = strdup("hello world");
	int code = strcmp(s1, s2);
	free(s1);
	return (code);
}