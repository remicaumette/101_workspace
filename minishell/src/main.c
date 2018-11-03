/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 19:08:06 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	handle_cmd(char **args)
{
	char	*cmd;
	char	*params[ft_strarr_len(args)];
	int		i;
	int		pid;

	cmd = args[0];
	i = 0;
	while (++i < ft_strarr_len(args))
		params[i] = args[i];
	params[++i] = 0;
	pid = fork();
	if (pid)
		wait(&pid);
	else
	{
		execv(cmd, args);
	}
}

int	main(void)
{
	t_minishell	minishell;

	minishell_init(&minishell);
	return (minishell_start(&minishell));
}
