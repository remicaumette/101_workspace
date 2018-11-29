/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ls.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 20:13:09 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 16:45:41 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	ls_init(t_ls *ls)
{
	struct winsize	size;

	ls->slash = 0;
	ls->reverse = 0;
	ls->recursive = 0;
	ls->hidden = 0;
	ls->print_header = 0;
	ls->display = vertical_display;
	ls->sort = sort_by_name;
	ls->term_width = ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) == -1 ?
		0 : size.ws_col;
	dirinfo_init(ls, NULL);
}

void	ls_printerror(char *filename)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

int		ls_printfiles(t_ls *ls, char **files)
{
	int			i;
	t_fileinfo	*file;

	if (dirinfo_init(ls, ""))
		return (1);
	i = -1;
	while (files[++i])
	{
		if (!(file = fileinfo_create(ls->dir.path, files[i])))
			return (1);
		dirinfo_insert_file(ls, file);
	}
	ls->display(ls);
	ls->print_header = 1;
	dirinfo_destroy(&ls->dir);
	return (0);
}

int		ls_printdir(t_ls *ls, char *dir, int println)
{
	int		i;
	char	**directories;

	i = -1;
	directories = NULL;
	if (ls->print_header)
	{
		if (println)
			ft_putchar('\n');
		ft_putstr(dir);
		ft_putstr(":\n");
	}
	if (dirinfo_init(ls, dir) || dirinfo_aggregate(ls, &directories))
		return (1);
	ls->display(ls);
	ls->print_header = 1;
	dirinfo_destroy(&ls->dir);
	while (directories && directories[++i])
		ls_printdir(ls, directories[i], 1);
	ft_strarr_del(directories);
	return (0);
}
