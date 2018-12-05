/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 05:14:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:11:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_from_line(t_shell *shell)
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

t_cmd	*cmd_from_words(char **words)
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

int		cmd_resolve_exec(t_cmd *cmd)
{

	return (0);
}

void	cmd_destroy(t_cmd **cmd)
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
