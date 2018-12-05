#include "minishell.h"

int	builtin_exit(t_shell *shell, t_cmd *cmd)
{
	int	len;

	(void)shell;
	if ((len = ft_strarr_len(cmd->args)) > 1)
		return (minishell_printerr("exit", "too many arguments"));
	exit(len ? ft_atoi(*cmd->args) : 1);
}
