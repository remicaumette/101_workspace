/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_clear.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/16 15:28:30 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
int			action_move_up(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_first > shell->cursor->winsize.ws_row)
	{
		if ((tmp = tgetstr(TC_MOVE_UP, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		shell->cursor->pos.y--;
	}
	return (SUCCESS);
}

int			action_move_down(t_shell *shell)
{
	char	*tmp;

	if (shell->cursor->dist_last > shell->cursor->winsize.ws_row)
	{
		if ((tmp = tgetstr(TC_MOVE_DOWN, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		shell->cursor->pos.y++;
	}
	return (SUCCESS);
}
*/
/*
**	<-
*/

int			action_move_left(t_shell *shell)
{
	char	*tmp;

	if (shell->line->cursor > 1)
	{
		if ((tmp = tgetstr(TC_MOVE_LEFT, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		if (shell->line->cursor > shell->line->size)
		{
			if ((tmp = tgetstr(TC_INSER_START, NULL)) == NULL)
				return (FAIL);
			ft_putstr(tmp);
		}
		shell->line->cursor--;
	}
	return (SUCCESS);
}

/*
**	->
*/

int			action_move_right(t_shell *shell)
{
	char	*tmp;

	if (shell->line->cursor <= shell->line->size)
	{
		if ((tmp = tgetstr(TC_MOVE_RIGHT, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		if (shell->line->cursor == shell->line->size)
		{
			if ((tmp = tgetstr(TC_INSER_STOP, NULL)) == NULL)
				return (FAIL);
			ft_putstr(tmp);
		}
		shell->line->cursor++;
	}
	return (SUCCESS);
}
