/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 05:06:23 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *token)
{
	char symbols[3][20] = { "WORD", "OPERATOR", "NEWLINE" };
	char operators[11][20] = { "NONE", "AND_IF", "OR_IF", "DSEMI", "DLESS", "DGREAT", "LESSAND", "GREATAND", "LESSGREAT", "DLESSDASH", "CLOBBER" };
	printf("=== START TOKENS PRINT\n");
	while (token)
	{
		printf("token->symbol = %s\n", symbols[token->symbol]);
		printf("token->op = %s\n", operators[token->op]);
		printf("token->content = \"%s\"\n", token->content);
		printf("token->prev = %p\n", token->prev);
		printf("token->next = %p\n", token->next);
		token = token->next;
		if (token)
			printf("->\n");
	}
	printf("=== END TOKENS PRINT\n");
}

int		main(int argc, char **argv, char **environ)
{
	(void)environ;

	if (argc > 1)
	{
		t_token	*tokens;
		tokens = lexer_tokenize(argv[1]);
		print_tokens(tokens);
		token_destroy(tokens);
	}
	return (0);
}
