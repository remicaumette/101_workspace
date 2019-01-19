/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_return.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 15:28:52 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 15:38:19 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_return(t_shell *shell)
{
	write(1, "\n", 1);
	if (shell->line->content)
	{
		if (lexer_tokenize(shell->lexer, shell->line->content))
			return (!!shell->line->content);
		shell->missing_token = lexer_getmissingtoken(shell->lexer);
		if (shell->lexer->begin)
		{
			if (shell->missing_token == -1)
				printf("shell_processline: %d\n", shell_processline(shell));
			lexer_cleanup(shell->lexer);
			parser_cleanup(shell->parser);
		}
		if (!(history_insert(shell->history, shell->line->content)))
			return (FAIL);
		line_reset(shell->line);
	}
	shell_prompt(shell);
	return (SUCCESS);
}
