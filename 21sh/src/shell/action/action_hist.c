/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_hist.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:24:17 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 13:55:19 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int					action_hist_up(t_shell *shell)
{
	t_histentry	*entry;
	char		*tmp;

	if ((entry = shell->history->curr ? shell->history->curr : shell->history->begin))
	{
		shell->history->curr = entry->next;
		if (!(tmp = tgetstr(TC_DEL_LINE, NULL)))
			return (FAIL);
		ft_putstr(tmp);
		shell_prompt(shell);
		ft_putstr(entry->content);
		line_replace(shell->line, ft_strdup(entry->content));
	}
	return (SUCCESS);
}

int					action_hist_down(t_shell *shell)
{
	t_histentry	*entry;
	char		*tmp;

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
