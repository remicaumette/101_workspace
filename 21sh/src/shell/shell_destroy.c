/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_destroy.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 17:18:55 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 17:19:10 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->environment)
			ft_strarr_del(shell->environment);
		if (shell->line)
			ft_strdel(&shell->line);
		if (shell->history)
			ft_strarr_del(shell->history);
		if (shell->lexer)
			lexer_destroy(shell->lexer);
		if (shell->parser)
			parser_destroy(shell->parser);
		ft_memdel((void **)&shell);
	}
}
