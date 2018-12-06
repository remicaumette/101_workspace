/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 05:14:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 15:06:35 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			cmd_from_line(t_shell *shell)
{
	char	**words;
	t_cmd	*cmd;

	words = NULL;
	if (words_from_line(shell, &words))
		return (1);
	if (!words)
		return (0);
	if (!(cmd = cmd_from_words(words)))
		return (1);
	ft_strarr_del(words);
	shell->current = cmd;
	return (0);
}

t_cmd		*cmd_from_words(char **words)
{
	t_cmd	*cmd;
	int		i;

	if (!(cmd = ft_memalloc(sizeof(t_cmd))))
		return (NULL);
	cmd->exec = NULL;
	if (!(cmd->cmd = ft_strdup(*words)))
		return (NULL);
	i = 0;
	while (words[++i])
		if (!(cmd->args = ft_strarr_add(cmd->args, words[i])))
			return (NULL);
	return (cmd);
}

static int	can_execute(char *filename)
{
	struct stat	stats;

	if (stat(filename, &stats))
		return (!(minishell_printerr(filename, "No such file or directory")));
	if (S_ISDIR(stats.st_mode))
		return (!(minishell_printerr(filename, "is a directory")));
	if (access(filename, X_OK))
		return (!(minishell_printerr(filename, "Permission denied")));
	return (1);
}

int			cmd_resolve_exec(t_shell *shell, t_cmd *cmd)
{
	char	*path;
	char	**paths;
	char	*tmp;
	int		i;

	if (!ft_strncmp("./", cmd->cmd, 2) || !ft_strncmp("../", cmd->cmd, 3) || *cmd->cmd == '/')
		return (!(can_execute(cmd->cmd) && (cmd->exec = ft_strdup(cmd->cmd))));
	if (!(path = shell_getenv(shell, "PATH")))
		return (1);
	if (!(paths = ft_strsplit(path, ':')))
		return (1);
	i = -1;
	while (paths[++i])
	{
		if (!(tmp = path_join(paths[i], cmd->cmd)))
		{
			ft_strarr_del(paths);
			return (1);
		}
		if (access(tmp, F_OK) || !(can_execute(tmp)))
		{
			ft_strdel(&tmp);
			continue ;
		}
		ft_strarr_del(paths);
		cmd->exec = tmp;
		return (0);
	}
	ft_strarr_del(paths);
	return (minishell_printerr(cmd->cmd, "command not found"));
}

void		cmd_destroy(t_cmd **cmd)
{
	if (cmd && *cmd)
	{
		if ((*cmd)->exec)
			ft_strdel(&(*cmd)->exec);
		if ((*cmd)->cmd)
			ft_strdel(&(*cmd)->cmd);
		if ((*cmd)->args)
			ft_strarr_del((*cmd)->args);
		ft_memdel((void **)cmd);
	}
}
