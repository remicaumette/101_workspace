/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   with_commas.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 19:48:07 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	display_file(t_ls *ls, t_fileinfo *file)
{
	static int	written = 0;
	char		str[ft_strlen(file->filename) + 3];
	int			i;

	if (!ls && !(written = 0))
		return ;
	i = -1;
	while (file->filename[++i])
		str[i] = file->filename[i];
	i--;
	if (ls->slash && S_ISDIR(file->stats->st_mode))
		str[++i] = '/';
	(!file->next) ? str[++i] = '\n' : 0;
	(file->next) ? str[++i] = ',' : 0;
	(file->next) ? str[++i] = ' ' : 0;
	str[++i] = 0;
	if (i + written > ls->term_width)
	{
		written = 0;
		ft_putstr("\n");
	}
	written += i;
	ft_putstr(str);
}

void		with_commas_display(t_ls *ls)
{
	t_fileinfo	*file;

	file = ls->dir.files;
	while (file)
	{
		display_file(ls, file);
		if (!file->next)
			display_file(NULL, file);
		file = file->next;
	}
}
