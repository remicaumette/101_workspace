/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 05:14:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 13:43:09 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_from_line(t_shell *shell)
{
	char	**split;

	if (!(split = plz_split_this(shell)))
		return (1);
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	return (0);
}

void	cmd_destroy(t_cmd *cmd)
{
	t_cmd	*curr;
	t_cmd	*next;

	next = cmd;
	while (next)
	{
		curr = next;
		next = curr->next;

		if (curr->cmd)
			ft_strdel(&curr->cmd);
		if (curr->args)
			ft_strarr_del(curr->args);
		ft_memdel((void **)&curr);
	}
}
