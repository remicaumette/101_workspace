#include "line_edit.h"

int		action_debug(t_shell *shell)
{
	int		fd;

	if ((fd = open("./debug.log", O_CREAT | O_RDWR | O_APPEND, S_IRWXU | S_IRWXO)) == -1)
		dprintf(2, "fail open debug.log\n");
	dprintf(fd, "\n");
	dprintf(fd, "Debug info form cursor\n");
	dprintf(fd, "shell->cursor->winsize: (x=%d,y=%d)\n", shell->cursor->winsize.ws_row, shell->cursor->winsize.ws_col);
	if (shell->cursor->current)
	{
		dprintf(fd, "shell->cursor->current=%c\n", shell->cursor->current->c);
		dprintf(fd, "All line=%s\n", ft_lCharto_str(ft_lCharfirst(shell->cursor->current)));
	}
	else
		dprintf(fd, "shell->cursor->current=NULL\n");
	dprintf(fd, "shell->cursor->dist_first=%d\n", shell->cursor->dist_first);
	dprintf(fd, "shell->cursor->dist_last=%d\n", shell->cursor->dist_last);
	return (SUCCESS);
}
