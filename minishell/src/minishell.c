/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 07:20:24 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		minishell_init(t_minishell *shell, char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	if (!(shell->environ = ft_memalloc(sizeof(*environ) * (i + 1))))
		return (0);
	i = -1;
	while (environ[++i])
		if (!(shell->environ[i] = ft_strdup(environ[i])))
			return (0);
	shell->environ[i] = NULL;
	return (1);
}

int		minishell_start(t_minishell *shell)
{
	t_command	cmd;
	int			readed;
	char		*line;

	ft_putstr("$> ");
	while ((readed = get_next_line(0, &line)) > 0)
	{
		if (*ft_strtrim(line))
		{
			if (command_parse(shell, &cmd, line) == 0)
				return (0);
			printf("cmd: %s\n", cmd.cmd);
			printf("arguments: ");
			for (int i = 0; cmd.arguments[i]; i++)
				printf("%s ", cmd.arguments[i]);
			printf("\n");
		}
		free(line);
		ft_putstr("$> ");
	}
	return (readed != -1);
}
