/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cd.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:34:09 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 17:21:37 by rcaumett    ###    #+. /#+    ###.fr     */
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
	char		*dir;

	if ((len = ft_strarr_len(cmd->args)) > 1)
		return (minishell_printerr("cd", "Too many arguments"));
	dir = len ? *cmd->args : shell->home;
	if (stat(dir, &stats))
		return (file_error(dir, "No such file or directory"));
	if (!S_ISDIR(stats.st_mode))
		return (file_error(dir, "Not a directory"));
	if (!opendir(dir))
		return (file_error(dir, "Permission denied"));
	return (!!chdir(dir));
}
