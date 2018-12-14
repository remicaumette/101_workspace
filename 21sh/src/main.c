/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:31:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 16:37:49 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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

int			main(void)
{
	t_lexer	*lexer;
	char	*line;

	if (!(lexer = lexer_create()))
		return (1);
	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		printf("lexer_tokenize = %d\n", lexer_tokenize(lexer, line));
		if (lexer->begin)
			print_token(lexer->begin);
		ft_strdel(&line);
		lexer_cleanup(lexer);
	}
	lexer_destroy(lexer);
	return (0);
}
