/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:34:03 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 15:12:37 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(t_shell *shell, t_cmd *cmd)
{
	int	len;

	(void)shell;
	if ((len = ft_strarr_len(cmd->args)) > 1)
		return (minishell_printerr("exit", "too many arguments"));
	shell->exit = len ? ft_atoi(*cmd->args) : 1;
	shell->read = 0;
	return (0);
}
