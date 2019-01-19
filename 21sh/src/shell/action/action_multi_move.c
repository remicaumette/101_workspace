/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_multi_move.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/17 13:07:08 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_move_first(t_shell *shell)
{
	while (shell->line->cursor != 1)
		action_move_left(shell);
	return (SUCCESS);
}

int		action_move_end(t_shell *shell)
{
	while (shell->line->cursor <= shell->line->size)
		action_move_right(shell);
	return (SUCCESS);
}
/*
TODO
int		action_move_next_word(t_shell *shell)
{
	if (shell->line->cursor <= shell->line->size)
	{
		while (shell->line->content[shell->line->cursor] && shell->line->content[shell->line->cursor] != ' ')
			action_move_right(shell);
		while (shell->line->content[shell->line->cursor] && shell->line->content[shell->line->cursor] == ' ')
			action_move_right(shell);
	}
	return (SUCCESS);
}

int		action_move_prev_word(t_shell *shell)
{
	if (shell->cursor->dist_first > 0)
	{
		action_move_left(shell);
		while (shell->cursor->current->c == ' ')
			action_move_left(shell);
		while (shell->cursor->dist_first != 0
				&& shell->cursor->current->prev->c != ' ')
			action_move_left(shell);
	}
	return (SUCCESS);
}
*/
