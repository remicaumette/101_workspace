/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 16:31:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/09 15:05:52 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			main(int argc, char **argv, char **environment)
{
	(void)argc;
	(void)argv;
	if (!(g_shell = shell_create(environment)) || shell_start(g_shell))
		return (1);
	shell_destroy(g_shell);
	return (0);
}
