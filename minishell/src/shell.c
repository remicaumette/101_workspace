/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 13:33:18 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		shell_init(t_shell *shell, char **environ)
{
	int		i;
	char	*tmp;

	i = -1;
	while (environ[++i])
		if (!(shell->environ = ft_strarr_add(shell->environ, environ[i])))
			return (1);
	tmp = shell_getenv(shell, "HOME");
	if (!(shell->home = ft_strdup(tmp ? tmp : "/")))
		return (1);
	tmp = shell_getenv(shell, "PWD");
	if (!(shell->cwd = ft_strdup(tmp ? tmp : shell->home)))
		return (1);
	shell->current = NULL;
	return (0);
}

void	shell_destroy(t_shell *shell)
{
	if (shell)
	{
		if (shell->environ)
			ft_strarr_del(shell->environ);
		if (shell->home)
			ft_strdel(&shell->home);
		if (shell->cwd)
			ft_strdel(&shell->cwd);
		if (shell->line)
			ft_strdel(&shell->line);
		if (shell->current)
			cmd_destroy(shell->current);
	}
}

int		shell_eval(t_shell *shell)
{
	ft_putstr("$> ");
	while (get_next_line(0, &shell->line))
	{
		if (cmd_from_line(shell))
			return (1);
		
		// if (shell->current && cmd_run(shell, ))
		cmd_destroy(shell->current);
		ft_strdel(&shell->line);
		ft_putstr("$> ");
	}
	return (0);
}

char	*shell_getenv(t_shell *shell, char *var)
{
	int		i;
	char	*delimiter;

	(void)var;
	i = -1;
	while (shell->environ[++i])
	{
		if (!(delimiter = ft_strchr(shell->environ[i], '=')))
			continue ;
		if (ft_strnequ(shell->environ[i], var, delimiter - shell->environ[i]))
			return (delimiter + 1);
	}
	return (NULL);
}
