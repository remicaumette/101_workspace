#include "shell.h"

void	parser_destroy(t_parser *parser)
{
	if (parser)
	{
		parser_cleanup(parser);
		ft_memdel((void **)&parser);
	}
}
