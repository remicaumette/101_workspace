/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:34:06 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 16:54:07 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *shell, t_cmd *cmd)
{
	int	i;

	(void)cmd;
	i = -1;
	while (shell->env[++i])
		ft_putendl(shell->env[i]);
	return (0);
}
