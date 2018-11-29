/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   horizontal.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 15:34:31 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	display_file(t_ls *ls, t_fileinfo *file, int spacing)
{
	static int	written = 0;
	char		str[spacing + 1];
	int			i;

	if (file == NULL && !(written = 0))
		return ;
	i = -1;
	while (file->filename[++i])
		str[i] = file->filename[i];
	i--;
	if (ls->slash && S_ISDIR(file->stats->st_mode))
		str[++i] = '/';
	if (!(written + spacing > ls->term_width))
		while (i < spacing - 1)
			str[++i] = ' ';
	str[++i] = 0;
	written += spacing;
	ft_putstr(str);
	if (written + spacing > ls->term_width)
	{
		ft_putchar('\n');
		written = 0;
	}
}

void		horizontal_display(t_ls *ls)
{
	t_fileinfo	*file;
	const int	spacing = 8 + ((ls->dir.filename_width + ls->slash) / 8) * 8;

	file = ls->dir.files;
	while (file)
	{
		if (!file->next)
			display_file(ls, file, (int)ft_strlen(file->filename) + ls->slash);
		else
			display_file(ls, file, spacing);
		file = file->next;
		if (!file)
		{
			ft_putstr("\n");
			display_file(NULL, NULL, spacing);
		}
	}
}
