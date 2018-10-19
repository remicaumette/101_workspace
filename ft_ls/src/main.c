/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 18:13:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_directory(t_flags *flags, t_dirinfo *dir)
{
	if (flags->display == one_per_line)
		one_per_line_display(flags, dir->files);
	if (flags->display == long_format)
	{
		ft_putstr("total ");
		ft_putnbr(dir->total);
		ft_putchar('\n');
		long_format_display(flags, dir, dir->files);
	}
}

int		list_directory(t_flags *flags, t_dirinfo *dir, char *path)
{
	dirinfo_init(dir, path);
	if (!dirinfo_aggregate(dir, flags))
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	display_directory(flags, dir);
	fileinfo_recursive_destroy(&dir->files);
	ft_strdel(&dir->path);
	return (0);
}

int		main(int argc, char **argv)
{
	t_flags			flags;
	t_dirinfo		dir;
	int				i;
	int				status;

	parse_flags(&flags, argv);
	i = 0;
	status = 0;
	while (++i < argc)
		if (argv[i][0] != '-')
			break ;
	i--;
	if ((i + 1) == argc)
		status = list_directory(&flags, &dir, ".");
	else
		while (++i < argc)
			status |= list_directory(&flags, &dir, argv[i]);
	return (status);
}
