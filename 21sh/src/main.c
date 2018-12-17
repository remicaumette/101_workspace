/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:31:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 16:06:59 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static const char *type[] = {
	"T_WORD",
	"T_NEWLINE",
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

void		print_token(t_token *token)
{
	printf("=== TOKEN\n");
	printf("token->type: %s\n", type[token->type]);
	printf("token->content: %s\n", token->content);
	printf("token->next: %p\n", token->next);
	if (token->next)
		print_token(token->next);
}

int			main(int argc, char **argv, char **environment)
{
	char	*line;
	char	open;

	(void)argc;
	(void)argv;
	if (!(g_shell = shell_create(environment)))
		return (1);
	while (1)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		if (lexer_tokenize(g_shell->lexer, line))
			return (1);
		if ((open = lexer_getmissingtoken(g_shell->lexer)) != -1)
		{
			printf("required: %c\n", open);
			continue ;
		}
		if (g_shell->lexer->begin)
		{
			// print_token(g_shell->lexer->begin);
			printf("=== PARSER\n");
			printf("parser_parse = %d\n", parser_parse(g_shell->parser));
		}
		ft_strdel(&line);
		lexer_cleanup(g_shell->lexer);
		parser_cleanup(g_shell->parser);
	}
	shell_destroy(g_shell);
	return (0);
}
