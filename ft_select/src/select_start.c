/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   select_start.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/19 19:47:18 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/20 19:17:47 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_select.h"

static int	select_readline(t_select *select)
{
	char	buf[4];
	int		readed;

	select_render(select);
	while ((readed = read(0, buf, 4)) > 0)
	{
		ft_bzero(buf + readed, 4 - readed);
		if (select_action_dispatcher(select, buf))
			return (1);
	}
	return (readed == -1);
}

int			select_start(t_select *select)
{
	struct termios	term;

	if (tgetent(NULL, getenv("TERM")) == -1)
		return (1);
	if (tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (1);
	return (select_readline(select));
}
