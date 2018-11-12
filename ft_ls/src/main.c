/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:55:04 by rcaumett    ###    #+. /#+    ###.fr     */
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
	if (options->args_count > 1 || options->paths_curr > 0)
	{
		ft_putstr(dir->path);
		ft_putstr(":\n");
	}
	if (options->display == long_format_display &&
		dir->total != -1 && dir->files)
	{
		ft_putstr("total ");
		ft_putnbr(dir->total);
		ft_putchar('\n');
	}
	if (dir->files)
		display_file(options, dir, dir->files, fileinfo_last(dir->files));
	if (options->args_curr + 1 < options->args_count ||
		options->paths_curr < options->paths_count)
		ft_putchar('\n');
}

static int	error_directory(t_options *options, t_dirinfo *dir)
{
	char	*tmp;

	if (options->paths_curr > 0)
	{
		ft_putstr(dir->path);
		ft_putstr(":\n");
	}
	if (!(tmp = ft_strrchr(dir->path, '/')))
		tmp = dir->path;
	else
		tmp++;
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(tmp, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	ft_strdel(&dir->path);
	if (dir->files)
		fileinfo_recursive_destroy(&dir->files);
	if (options->paths_curr < options->paths_count)
		ft_putchar('\n');
	return (1);
}

static int	list_directory(t_options *options, t_dirinfo *dir, char *path)
{
	char	**paths;
	int		i;
	int		status;

	paths = NULL;
	status = 0;
	dirinfo_init(dir, path);
	if (dir->path == NULL)
		return (1);
	if (!dirinfo_aggregate(dir, options, &paths))
		return (error_directory(options, dir));
	ft_strarr_sort(paths, options->reverse);
	display_directory(options, dir);
	if (dir->files)
		fileinfo_recursive_destroy(&dir->files);
	i = -1;
	ft_strdel(&dir->path);
	while (paths && paths[++i] && ++options->paths_curr)
		status |= list_directory(options, dir, paths[i]);
	ft_strarr_del(paths);
	return (status);
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
	while (options.args[++options.args_curr] &&
		!(options.paths_count = 0) &&
		!(options.paths_curr = 0))
		status |= list_directory(&options, &dir,
			options.args[options.args_curr]);
	ft_strarr_del(options.args);
	return (status);
}
