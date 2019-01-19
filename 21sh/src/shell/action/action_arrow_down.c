/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_down.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:31:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_arrow_down(t_shell *shell)
{
	t_histentry *entry;
	char *tmp;

	if ((entry = shell->history->curr ? shell->history->curr : shell->history->end))
	{
		shell->history->curr = entry->prev;
		if (!(tmp = tgetstr(TC_DEL_LINE, NULL)))
			return (FAIL);
		ft_putstr(tmp);
		shell_prompt(shell);
		ft_putstr(entry->content);
		line_replace(shell->line, ft_strdup(entry->content));
	}
	return (SUCCESS);
}
