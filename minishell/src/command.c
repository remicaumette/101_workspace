/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   command.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 05:14:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 05:15:33 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_word(t_minishell *shell, char *word)
{
	(void)shell;
	return (ft_strdup(word));
}

int			command_parse(t_minishell *shell, t_command *command, char *line)
{
	char	**split;
	int		i;

	if (!(split = ft_strsplit(line, ' ')))
		return (0);
	command->cmd = parse_word(shell, split[0]);
	if (!(command->arguments = ft_memalloc(sizeof(char **) *
		ft_strarr_len(split))))
		return (0);
	i = 0;
	while (split[++i])
		command->arguments[i] = parse_word(shell, split[i]);
	ft_strarr_del(split);
	return (1);
}
