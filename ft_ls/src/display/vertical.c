/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vertical.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:19 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 19:44:39 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

#include <stdio.h>
static void	print_file(t_options *options, t_dirinfo *dir, t_fileinfo *file, t_fileinfo *last)
{
	char	s[dir->filename_width + 2];
	int		i;

	(void)options;
	(void)dir;
	i = -1;
	while (file->filename[++i])
		s[i] = file->filename[i];
	// printf("%d %d %d\n", options->width, options->width_curr, options->width_curr + dir->filename_width + 1);
	if (file != last && options->width > options->width_curr + ((dir->filename_width + 1) * 2))
	{
		--i;
		while (++i < dir->filename_width + 1)
			s[i] = ' ';
		options->width_curr += dir->filename_width + 1;
	}
	else
	{
		options->width_curr = 0;
		s[i++] = '\n';
	}
	s[i] = 0;
	ft_putstr(s);
}

void		vertical_display(t_options *options, t_dirinfo *dir, t_fileinfo *file, t_fileinfo *last)
{
	if (file->right)
		vertical_display(options, dir, file->right, last);
	print_file(options, dir, file, last);
	if (file->left)
		vertical_display(options, dir, file->left, last);
}
