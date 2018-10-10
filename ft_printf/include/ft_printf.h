#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"

// %[flags][width][.precision][size]type
typedef struct	s_printf_arg
{
	int		offset;
	int		limit;
	char	*flags;
	int		width;
	int		precision;
	int		size;
	char	*type;
}				t_printf_arg;
#endif
