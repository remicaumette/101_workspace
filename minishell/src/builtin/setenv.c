/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setenv.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 14:09:17 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 14:13:36 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_setenv(t_shell *shell, t_cmd *cmd)
{
	int		len;
	int		i;
	char	*delimiter;
	int		pos;

	if ((len = ft_strarr_len(cmd->args)) > 1)
		return (minishell_printerr("setenv", "too many arguments"));
	else if (len < 1)
		return (0);
	if (!(delimiter = ft_strchr(*cmd->args, '=')))
		return (minishell_printerr("setenv", "invalid arguments"));
	i = -1;
	pos = -1;
	while (shell->env[++i])
		if (ft_strncmp(*cmd->args, shell->env[i],
			delimiter - *cmd->args) == 0 && (pos = i) != -1)
			break ;
	if (pos != -1)
	{
		ft_strdel(&shell->env[pos]);
		shell->env[pos] = ft_strdup(*cmd->args);
	}
	else
		shell->env = ft_strarr_add(shell->env, *cmd->args);
	return (0);
}
