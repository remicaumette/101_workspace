/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 15:12:56 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	fail(t_shell *shell)
{
	shell_destroy(shell);
	return (1);
}

int	main(int argc, char **argv, char **environ)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	if (shell_init(&shell, environ) || shell_eval(&shell))
		return (fail(&shell));
	shell_destroy(&shell);
	return (shell.exit);
}
