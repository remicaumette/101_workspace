#include "minishell.h"

int	builtin_env(t_shell *shell, t_cmd *cmd)
{
	int	i;

	(void)cmd;
	i = -1;
	while (shell->env[++i])
		ft_putendl(shell->env[i]);
	return (0);
}
