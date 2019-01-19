/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   action_del.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: timfuzea <tifuzeau@student.42.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 14:27:00 by timfuzea     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/15 14:40:10 by timfuzea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		action_backdel(t_shell *shell)
{
	char	*tmp;

	if (shell->line->cursor > 1)
	{
		if ((tmp = tgetstr(TC_MOVE_LEFT, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		if ((tmp = tgetstr(TC_DEL, NULL)) == NULL)
			return (FAIL);
		ft_putstr(tmp);
		line_backdel(shell->line);
	}
	return (SUCCESS);
}
