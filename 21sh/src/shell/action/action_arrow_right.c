/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_arrow_right.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 16:48:33 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:31:35 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	action_arrow_right(t_shell *shell)
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
