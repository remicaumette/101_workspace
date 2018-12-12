/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unsetenv.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 14:09:20 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 14:09:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_unsetenv(t_shell *shell, t_cmd *cmd)
{
	int		len;
	int		i;
	char	**env;

	len = ft_strarr_len(cmd->args);
	if (len > 1)
		return (minishell_printerr("unsetenv", "too many arguments"));
	else if (len < 1)
		return (0);
	env = NULL;
	i = -1;
	while (shell->env[++i])
	{
		if (ft_strcmp(*cmd->args, shell->env[i]) <= 0)
			continue ;
		if (!(env = ft_strarr_add(env, shell->env[i])))
			return (1);
	}
	ft_strarr_del(shell->env);
	shell->env = env;
	return (0);
}
