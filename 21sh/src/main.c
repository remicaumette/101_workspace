#include "shell.h"

int	main(int argc, char **argv)
{
	t_lexer	*lexer;

	if (argc == 2)
	{
		if (!(lexer = lexer_create()))
			return (1);
		printf("lexer_tokenize = %d\n", lexer_tokenize(lexer, argv[1]));
	}
	return (0);
}
