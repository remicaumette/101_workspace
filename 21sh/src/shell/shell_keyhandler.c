/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_keyhandler.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 14:13:40 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:50:38 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	shell_basic_keyhandler(t_shell *shell, char *buf, int readed)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(shell->line, buf)))
		return (1);
	write(1, buf, readed);
	ft_strdel(&shell->line);
	shell->line = tmp;
	return (0);
}

int	shell_arrow_keyhandler(t_shell *shell, char *buf, int readed)
{
		// up 27 91 65
// down 27 91 66
// left 27 91 68
// right 27 91 67
	(void)shell;
	(void)buf;
	(void)readed;
	return (0);
}

int	shell_ctrl_keyhandler(t_shell *shell, char *buf, int readed)
{
	(void)shell;
	(void)buf;
	(void)readed;
	return (0);
}

int	shell_enter_keyhandler(t_shell *shell)
{
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
