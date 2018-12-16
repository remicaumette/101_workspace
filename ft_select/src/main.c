#include "ft_select.h"

int	main(void)
{
	int				status;
	struct termios	term;

	if ((status = tgetent(NULL, getenv("TERM"))) == -1)
		ft_putendl_fd("terminfo database could not be found.", 2);
	else if (status == -1)
		ft_putendl_fd("there is no such entry for this terminal.", 2);
	else
	{
		if (tcgetattr(0, &term) == -1)
			return (1);
		term.c_lflag &= ~(ICANON);
		term.c_lflag &= ~(ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSANOW, &term) == -1)
			return (1);
		
		char buf[3];
		printf("hello world\n");
		while (1)
		{
			read(0, buf, 3);
			if (buf[0] == 27 && buf[1] == 91)
				tputs(tgoto(tgetstr("cm", NULL), 5, 5), 1, putchar);
			putchar('\n');
			//tputs(tgetstr(Co))
			printf("%d %d %d\n", buf[0], buf[1], buf[2]);
		}
		return (0);
	}
	return (1);
}
