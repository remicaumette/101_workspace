/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   echo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 14:09:09 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 16:53:02 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_echo(t_shell *shell, t_cmd *cmd)
{
	int	i;

	(void)shell;
	i = -1;
	while (cmd->args && cmd->args[++i])
	{
		ft_putstr(cmd->args[i]);
		if (cmd->args[i + 1])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (0);
}
