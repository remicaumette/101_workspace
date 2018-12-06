/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:33:34 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 15:33:37 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			process_run(t_shell *shell, t_cmd *cmd)
{
	t_builtin	builtin;
	pid_t		pid;
	int			status;
	char		**argv;


	if ((builtin = builtin_from_name(cmd->cmd)))
		return (builtin(shell, cmd));
	if (!(argv = ft_strarr_add(NULL, cmd->exec)))
		return (1);
	status = -1;
	while (cmd->args && cmd->args[++status])
		if (!(argv = ft_strarr_add(argv, cmd->args[status])))
			return (1);
	pid = fork();
	if (pid)
		wait(&pid);
	else
	{
		if ((status = execve(cmd->exec, argv, shell->env)) == -1)
			return (1);
		ft_strarr_del(argv);
		return (status);
	}
	return (1);
}
