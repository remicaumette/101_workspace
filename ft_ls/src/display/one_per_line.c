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

void	one_per_line_display(t_options *options, t_fileinfo *file)
{
	if (file->right)
		one_per_line_display(options, file->right);
	ft_putendl(file->filename);
	if (file->left)
		one_per_line_display(options, file->left);
}
