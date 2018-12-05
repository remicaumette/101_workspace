/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:06:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		shell_init(t_shell *shell, char **environ)
{
	int		i;
	char	*home;
	char	cwd[1024];

	i = -1;
	while (environ[++i])
		if (!(shell->env = ft_strarr_add(shell->env, environ[i])))
			return (1);
	home = shell_getenv(shell, "HOME");
	if (!(shell->home = ft_strdup(home ? home : "/")))
		return (1);
	if (chdir(getcwd(cwd, 1024)))
		return (1);
	shell->current = NULL;
	return (0);
}

void	shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->env)
			ft_strarr_del(shell->env);
		if (shell->home)
			ft_strdel(&shell->home);
		if (shell->line)
			ft_strdel(&shell->line);
		if (shell->current)
			cmd_destroy(shell->current);
	}
}

void	debug_cmd(t_cmd *cmd)
{
	printf("cmd: %s args: %p\n", cmd->cmd, cmd->args);
	for (int i = 0; cmd->args && cmd->args[i]; i++)
		printf("\t- %s\n", cmd->args[i]);
	if (cmd->next)
		debug_cmd(cmd->next);
}

int		shell_eval(t_shell *shell)
{
	char	cwd[1024];

	while (1)
	{
		if (!(getcwd(cwd, 1024)))
			return (1);
		ft_putstr(cwd);
		ft_putstr(" ~> ");
		if (get_next_line(0, &shell->line) <= 0)
			break ;
		if (cmd_from_line(shell))
			return (1);
		if (shell->current)
		{
			debug_cmd(shell->current);
		}
		cmd_destroy(shell->current);
		ft_strdel(&shell->line);
	}
	return (0);
}

char	*shell_getenv(t_shell *shell, char *name)
{
	int		i;
	char	*delimiter;

	i = -1;
	while (shell->env[++i])
	{
		if (!(delimiter = ft_strchr(shell->env[i], '=')))
			continue ;
		if (ft_strnequ(shell->env[i], name, delimiter - shell->env[i]))
			return (delimiter + 1);
	}
	return (NULL);
}

int		shell_setenv(t_shell *shell, char *value)
{
	(void)shell;
	(void)value;
	return (0);
}
