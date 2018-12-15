/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:27:49 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 20:24:57 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell		*shell_create(char **environment)
{
	t_shell	*shell;
	int		i;

	if (!(shell = ft_memalloc(sizeof(t_shell))))
		return (NULL);
	i = -1;
	while (environment[++i])
		if (!(shell->environment = ft_strarr_add(shell->environment,
			environment[i])))
			return (NULL);
	shell->history = NULL;
	if (!(shell->lexer = lexer_create()))
		return (NULL);
	if (!(shell->parser = parser_create(shell)))
		return (NULL);
	return (shell);
}

void		shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->environment)
			ft_strarr_del(shell->environment);
		if (shell->history)
			ft_strarr_del(shell->history);
		if (shell->lexer)
			lexer_destroy(shell->lexer);
		if (shell->parser)
			parser_destroy(shell->parser);
		ft_memdel((void **)&shell);
	}
}
