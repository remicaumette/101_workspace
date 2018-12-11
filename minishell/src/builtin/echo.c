#include "minishell.h"

int	builtin_echo(t_shell *shell, t_cmd *cmd)
{
	int	i;

	(void)shell;
	i = -1;
	while (cmd->args[++i])
	{
		ft_putstr(cmd->args[i]);
		if (cmd->args[i + 1])
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (0);
}
