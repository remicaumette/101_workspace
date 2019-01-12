/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_return.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 14:50:00 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 14:51:16 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_return(t_shell *shell, char *buf, int readed)
{
	(void)buf;
	(void)readed;
	write(1, "\n", 1);
	if (!shell->line || lexer_tokenize(shell->lexer, shell->line))
		return (!!shell->line);
	shell->missing_token = lexer_getmissingtoken(shell->lexer);
	if (shell->lexer->begin)
	{
		if (shell->missing_token == -1)
		{
			printf("=== TOKEN\n");
			print_token(shell->lexer->begin);
			printf("=== PARSER\n");
			printf("parser_parse = %d\n", parser_parse(shell->parser));
			print_node(shell->parser->root);
		}
		lexer_cleanup(shell->lexer);
		parser_cleanup(shell->parser);
	}
	ft_strdel(&shell->line);
	return (0);
}
