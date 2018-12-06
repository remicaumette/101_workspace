/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:34:09 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 15:34:10 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int	file_error(char *file, char *msg)
{
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int			builtin_cd(t_shell *shell, t_cmd *cmd)
{
	int			len;
	struct stat	stats;

	if ((len = ft_strarr_len(cmd->args)) > 1)
		return (minishell_printerr("cd", "too many arguments"));
	if (!len)
		return (!!chdir(shell->home));
	if (stat(*cmd->args, &stats))
		return (file_error(*cmd->args, "No such file or directory"));
	if (!S_ISDIR(stats.st_mode))
		return (file_error(*cmd->args, "Not a directory"));
	return (!!chdir(len ? *cmd->args : shell->home));
}
