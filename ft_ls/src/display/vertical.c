// -C default

#include "ft_ls.h"
/*
static void	foreach_file(t_dirinfo *dir, t_fileinfo *file)
{
	if (dir->flags & FLAG_REVERSE_SORT)
		if (file->left)
			foreach_file(dir, file->left);
	else
		if (file->right)
			foreach_file(dir, file->right);
	
	if (dir->flags & FLAG_REVERSE_SORT)
		if (file->right)
			foreach_file(dir, file->right);
	else
		if (file->left)
			foreach_file(dir, file->left);
}
*/
void	vertical_display(t_dirinfo *info)
{
	struct winsize	ws;
	int				curr;

(void)info;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	curr = 0;




	printf("%d\n", ws.ws_col);
	for (int i = 0; i < ws.ws_col - 1; i++)
		ft_putchar(' ');
	ft_putchar('\n');
}
/*
static void	print(t_dirinfo *dir, t_fileinfo *file)
{
	int		i;
	char	s[dir->filename_width + 2];

	i = -1;
	while (file->filename[++i])
		s[i] = file->filename[i];
	while (i < dir->filename_width + 1)
		s[i++] = ' ';
	s[i] = 0;
	ft_putstr(s);
}
*/