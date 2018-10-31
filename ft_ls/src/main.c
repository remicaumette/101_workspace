/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 11:28:53 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	display_file(t_options *options, t_dirinfo *dir, t_fileinfo *file,
	t_fileinfo *last)
{
	if (file->right)
		display_file(options, dir, file->right, last);
	options->display(options, dir, file, last);
	if (file->left)
		display_file(options, dir, file->left, last);
}

static void	display_directory(t_options *options, t_dirinfo *dir)
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
		display_file(options, dir, dir->files, fileinfo_last(dir->files));
	if (options->args_curr + 1 < options->args_count ||
		options->paths_curr + 1 < options->paths_count)
		ft_putchar('\n');
}

static int	list_directory(t_options *options, t_dirinfo *dir, char *path)
{
	dirinfo_init(dir, path);
	if (!dirinfo_aggregate(dir, options))
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(dir->path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	ft_strarr_sort(options->paths, options->reverse);
	display_directory(options, dir);
	if (dir->files)
		fileinfo_recursive_destroy(&dir->files);
	ft_strdel(&dir->path);
	return (0);
}

int			main(int argc, char **argv)
{
	t_options	options;
	t_dirinfo	dir;
	int			status;

	(void)argc;
	status = options_init(&options, argv);
	options.args_curr = -1;
	if (!options.args)
		options.args = ft_strarr_add(options.args, ".");
	while (options.args[++options.args_curr])
	{
		options.paths_curr = -1;
		options.paths_count = 0;
		status |= list_directory(&options, &dir,
			options.args[options.args_curr]);
		while (options.paths && options.paths[++options.paths_curr])
			status |= list_directory(&options, &dir,
				options.paths[options.paths_curr]);
		ft_strarr_del(options.paths);
		options.paths = NULL;
	}
	ft_strarr_del(options.args);
	return (status);
}
