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

void	display_directory(t_dirinfo *dir)
{
	if (dir->flags->display == one_per_line)
		one_per_line_display(dir, dir->files);
	/*if (info->flags & FLAG_VERTICAL_FORMAT)
		vertical_display(info);
	if (info->flags & FLAG)*/
}

int		list_directory(t_flags *flags, char *path)
{
	t_dirinfo	*info;

	if (!(info = dirinfo_create(flags, path)) ||
		!dirinfo_aggregate(info))
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	display_directory(info);
	dirinfo_destroy(&info);
	return (0);
}

int		main(int argc, char **argv)
{
	t_flags			*flags;
	int				i;
	int				status;

	if (!(flags = parse_flags(argv)))
		return (1);
	i = 0;
	status = 0;
	while (++i < argc)
		if (argv[i][0] != '-')
			break ;
	i--;
	if ((i + 1) == argc)
		status = list_directory(flags, ".");
	else
		while (++i < argc)
			status |= list_directory(flags, argv[i]);
	ft_memdel((void **)&flags);
	return (status);
}
