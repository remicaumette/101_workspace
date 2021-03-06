/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   one_per_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 02:19:42 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 14:03:26 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	display_file(t_ls *ls, t_fileinfo *file)
{
	char	str[ft_strlen(file->filename) + 3];
	int		i;

	i = -1;
	while (file->filename[++i])
		str[i] = file->filename[i];
	if (ls->slash && S_ISDIR(file->stats->st_mode))
		str[i++] = '/';
	str[i++] = '\n';
	str[i++] = 0;
	ft_putstr(str);
}

void		one_per_line_display(t_ls *ls)
{
	t_fileinfo	*file;

	file = ls->dir.files;
	while (file)
	{
		display_file(ls, file);
		file = file->next;
	}
}
