/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:31:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 14:30:45 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	fail(t_shell *shell)
{
	shell_destroy(shell);
	return (1);
}

int	main(int argc, char **argv, char **environment)
{
	(void)argc;
	(void)argv;
	if (!(g_shell = shell_create(environment)) || shell_start(g_shell))
		return (fail(g_shell));
	shell_destroy(g_shell);
	return (0);
}
