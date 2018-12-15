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
	static const char *type[] = {
		"T_WORD",
		"T_NEWLINE",
		"T_SQUOTE",
		"T_DQUOTE",
		"T_PIPE",
		"T_ANDIF",
		"T_ORIF",
		"T_DSEMI",
		"T_DLESS",
		"T_DGREAT",
		"T_LESSAND",
		"T_GREATAND",
		"T_LESSGREAT",
		"T_DLESSDASH",
		"T_CLOBBER",
	};
	printf("=== TOKEN\n");
	printf("token->type: %s\n", type[token->type]);
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
