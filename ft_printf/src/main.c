#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

/*
static char	*concat(char **s1, char *s2)
{
	char	*tmp;

	if (!s1)
		return (NULL);
	if (!*s1)
		return (*s1 = ft_strdup(s2));
	else
	{
		if (!(tmp = ft_strjoin(*s1, s2)))
			return (NULL);
		ft_strdel(s1);
		return (*s1 = tmp);
	}
}
*/
void	internal_print(va_list ap)
{
	char *lol = va_arg(ap, char*);
	printf("%s\n", lol);
}

t_printf_arg	*printf_arg_create(int offset, int limit)
{
	t_printf_arg	*arg;

	if (!(arg = ft_memalloc(sizeof(*arg))))
		return (NULL);
	arg->offset = offset;
	arg->limit = limit;
	arg->flags = NULL;
	
}



int		ft_printf(const char *format, ...)
{
	va_list	ap;

	if (!format)
		return (0);
	va_start(ap, format);
	internal_print(ap);
	va_end(ap);
	return (0);
}

int		main(void)
{
	ft_printf(NULL);
	ft_printf("Hello world %s", "hello");
}
