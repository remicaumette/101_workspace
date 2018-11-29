/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vertical.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 17:28:33 by sifouche     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 15:55:09 by sifouche    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	display_file(t_ls *ls, t_fileinfo *file, int spacing)
{
	char	str[spacing + 1];
	int		i;

	i = 0;
	while (file->filename[i] != '\0')
	{
		str[i] = file->filename[i];
		i++;
	}
	if (ls->slash && S_ISDIR(file->stats->st_mode))
		str[i++] = '/';
	while (i < spacing)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
}

static void	display_tab(t_ls *ls, int nb_col,
		int nb_line, t_fileinfo *s[nb_col][nb_line])
{
	int c;
	int l;
	int lastelem;
	int nb;

	nb = ls->dir.files_count;
	l = -1;
	lastelem = nb - (nb_col - 1) * nb_line;
	while (nb && ++l < nb_line)
	{
		c = -1;
		while (nb && ++c < nb_col - 1 && nb--)
			if ((c == nb_col - 1 && !lastelem) || !nb)
				display_file(ls, s[c][l], ft_strlen(s[c][l]->filename));
			else
				display_file(ls, s[c][l],
					8 + ((ls->dir.filename_width + ls->slash) / 8) * 8);
		if (lastelem)
		{
			display_file(ls, s[c][l], ft_strlen(s[c][l]->filename));
			nb--;
			lastelem--;
		}
		ft_putstr("\n");
	}
}

static void	fill_tab(t_ls *ls, int nb, int nb_col, int nb_line)
{
	t_fileinfo	*file;
	t_fileinfo	*s[nb_col][nb_line];
	int			c;
	int			l;
	int			lastelem;

	file = ls->dir.files;
	lastelem = nb - (nb_col - 1) * nb_line;
	c = -1;
	while (file && ++c < nb_col)
	{
		l = -1;
		while (file && ++l < nb_line)
		{
			if (c == nb_col - 1)
				if (!(lastelem-- > 0))
					break ;
			s[c][l] = file;
			file = file->next;
		}
	}
	display_tab(ls, nb_col, nb_line, s);
}

static void	calc_size(t_ls *ls, int nb, int spacing)
{
	int nb_col;
	int nb_line;

	nb_col = 1;
	nb_line = 1;
	while (nb_col * nb_line < nb)
	{
		if (nb_col * spacing < ls->term_width - spacing)
			nb_col++;
		else
		{
			nb_col = 1;
			nb_line++;
		}
	}
	fill_tab(ls, nb, nb_col, nb_line);
}

void		vertical_display(t_ls *ls)
{
	int spacing;

	spacing = 8 + ((ls->dir.filename_width + ls->slash) / 8) * 8;
	calc_size(ls, ls->dir.files_count, spacing);
}
