/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 05:06:23 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
	t_minishell	shell;

	(void) argc;
	(void) argv;
	if (minishell_init(&shell, environ) == 0)
		return (1);
	return (!minishell_start(&shell));
}
