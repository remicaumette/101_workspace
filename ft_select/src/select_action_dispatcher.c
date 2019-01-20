/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_action_dispatcher.c                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/20 16:15:08 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:18:22 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

t_select_action	g_actions[] = {
	{ TC_KEY_ARROW_DOWN, action_arrow_down },
	{ TC_KEY_ARROW_LEFT, action_arrow_left },
	{ TC_KEY_ARROW_RIGHT, action_arrow_right },
	{ TC_KEY_ARROW_UP, action_arrow_up },
	{ TC_KEY_ESC, action_esc },
	{ TC_KEY_ESPACE, action_espace },
	{ TC_KEY_DELETE, action_backspace },
	{ TC_KEY_BACKSPACE, action_backspace },
	{ TC_KEY_RETURN, action_return },
};

int	select_action_dispatcher(t_select *select, char *buf)
{
	int i;

	i = -1;
	while (++i < 9)
		if (!(ft_memcmp(g_actions[i].key, buf, 4)))
			return (g_actions[i].handler(select));
	return (0);
}
