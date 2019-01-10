/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_start.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/09 15:15:02 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 14:51:27 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	shell_keyhandler_dispatcher(t_shell *shell, char *buf, int readed)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] >= 65 && buf[2] <= 68)
		return (shell_arrow_keyhandler(shell, buf, readed));
	if (buf[0] == 10 && readed == 1)
		return (shell_enter_keyhandler(shell));
	return (shell_basic_keyhandler(shell, buf, readed));
}

static int	shell_readline(t_shell *shell)
{
	int		readed;
	char	buf[4];

	while ((readed = read(0, buf, 3)) > 0)
	{
		ft_bzero(buf + readed, 4 - readed);
		if (buf[0] == 4 && buf[1] == 0 && buf[2] == 0)
			break ;
		if (shell_keyhandler_dispatcher(shell, buf, readed))
			return (1);
	}
	return (0);
}

int			shell_start(t_shell *shell)
{
	struct termios	term;

	if (tgetent(NULL, shell_getenv(shell, "TERM")) == -1 ||
		tcgetattr(0, &term) == -1)
		return (1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (1);
	return (shell_readline(shell));
}
