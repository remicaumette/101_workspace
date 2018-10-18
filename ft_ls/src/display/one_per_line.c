#include "ft_ls.h"

void	one_per_line_display(t_dirinfo *dir, t_fileinfo *file)
{
	if (dir->flags->reverse)
	{
		if (file->left)
			one_per_line_display(dir, file->left);
		ft_putendl(file->filename);
		if (file->right)
			one_per_line_display(dir, file->right);
	}
	else
	{
		if (file->right)
			one_per_line_display(dir, file->right);
		ft_putendl(file->filename);
		if (file->left)
			one_per_line_display(dir, file->left);
	}
}
