/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:18:03 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	minishell_init(t_minishell *minishell)
{
	(void)minishell;
	printf("%s\n", environ[0]);
}

int		minishell_start(t_minishell *minishell)
{
	t_minishell_cmd	cmd;
	int				readed;
	char			*line;
	char			**args;

	ft_putstr("$> ");
	while ((readed = get_next_line(0, &line)) > 0)
	{
		if (*line)
		{
			if (minishell_parse_cmd(&cmd, line) == 0)
				return (0);
			if (minishell_run_cmd(minishell, &cmd) == 0)
				return (0);
		}
		ft_putstr("$> ");
	}
	return (readed != -1 ? 0 : 1);
}

int		minishell_parse_cmd(t_minishell_cmd *cmd, char *line)
{
	char	**split;
	char	*cmd;
	char	**args;
	int		i;

	if (!(args = ft_strsplit(line, ' ')))
		return (0);
	cmd = ft_strdup(args[0]);
	if (!(args = ft_memalloc(sizeof(*args) * ft_strarr_len(args))))
		return (0);
	i = 0;
	while (args[++i])
		args[i - 1] = split[i];
	free(args);
}

int		minishell_run_cmd(t_minishell *minishell, t_minishell_cmd *cmd)
{

}
