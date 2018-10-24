/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 19:52:12 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_directory(t_options *options, t_dirinfo *dir)
{
	if (options->args_count > 1 || options->paths_curr >= 0)
	{
		ft_putstr(dir->path);
		ft_putstr(":\n");
	}
	if (options->display == long_format_display && dir->total != -1)
	{
		ft_putstr("total ");
		ft_putnbr(dir->total);
		ft_putchar('\n');
	}
	if (dir->files)
		options->display(options, dir, dir->files, fileinfo_last(dir->files));
	if (options->args_curr + 1 < options->args_count ||
		options->paths_curr + 1 < options->paths_count)
		ft_putchar('\n');
}

int		list_directory(t_options *options, t_dirinfo *dir, char *path)
{
	dirinfo_init(dir, path);
	if (!dirinfo_aggregate(dir, options))
		return (1);
	strarr_sort(options->paths, options->reverse);
	display_directory(options, dir);
	fileinfo_recursive_destroy(&dir->files);
	ft_strdel(&dir->path);
	return (0);
}

int		main(int argc, char **argv)
{
	t_options	options;
	t_dirinfo	dir;
	int			status;

	(void)argc;
	status = options_init(&options, argv);
	options.args_curr = -1;
	if (!options.args)
		options.args = strarr_add(options.args, ".");
	while (options.args[++options.args_curr])
	{
		options.paths_curr = -1;
		options.paths_count = 0;
		status |= list_directory(&options, &dir,
			options.args[options.args_curr]);
		while (options.paths && options.paths[++options.paths_curr])
			status |= list_directory(&options, &dir,
				options.paths[options.paths_curr]);
		strarr_del(options.paths);
		options.paths = NULL;
	}
	strarr_del(options.args);
	return (status);
}
