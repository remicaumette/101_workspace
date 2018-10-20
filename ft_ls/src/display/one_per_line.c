#include "ft_ls.h"

void	one_per_line_display(t_options *options, t_fileinfo *file)
{
	if (file->right)
		one_per_line_display(options, file->right);
	ft_putendl(file->filename);
	if (file->left)
		one_per_line_display(options, file->left);
}
