#include "shell.h"

void		print_token(t_token *token)
{
	static const char type[4][20] = { "WORD", "OPERATOR", "NEWLINE", "IO_NUMBER" };
	static const char op[11][20] = { "NONE", "AND_IF", "OR_IF", "DSEMI", "DLESS", "DGREAT", "LESSAND", "GREATAND", "LESSGREAT", "DLESSDASH", "CLOBBER" };
	printf("=== TOKEN\n");
	printf("token->type: %s\n", type[token->type]);
	printf("token->op: %s\n", op[token->op]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n", token->next);
	if (token->next)
		print_token(token->next);
}

int	main(int argc, char **argv)
{
	t_lexer	*lexer;

	if (argc == 2)
	{
		if (!(lexer = lexer_create()))
			return (1);
		printf("lexer_tokenize = %d\n", lexer_tokenize(lexer, argv[1]));
		print_token(lexer->begin);
	}
	return (0);
}
