#include "ft_ls.h"

void	one_per_line_display(t_flags *flags, t_fileinfo *file)
{
	if (flags->reverse)
	{
		if (file->left)
			one_per_line_display(flags, file->left);
		ft_putendl(file->filename);
		if (file->right)
			one_per_line_display(flags, file->right);
	}
	else
	{
		if (file->right)
			one_per_line_display(flags, file->right);
		ft_putendl(file->filename);
		if (file->left)
			one_per_line_display(flags, file->left);
	}
}
