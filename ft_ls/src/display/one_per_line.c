/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   one_per_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:16 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 15:34:17 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	one_per_line_display(t_options *options, t_dirinfo *dir,
	t_fileinfo *file, t_fileinfo *last)
{
	(void)options;
	(void)dir;
	(void)last;
	ft_putendl(file->filename);
}
