/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 20:09:01 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 11:29:45 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	cleanup_memory(t_dirinfo *dir, char **args, char **files,
	char **directories)
{
	ft_strarr_del(args);
	ft_strarr_del(files);
	ft_strarr_del(directories);
	if (dir && dir->path)
		dirinfo_destroy(dir);
}

static int	fail(t_ls *ls, char **args, char **files, char **directories)
{
	cleanup_memory(&ls->dir, args, files, directories);
	return (1);
}

void		ft_strarr_sort(char **arr, int reverse)
{
	int		i;
	int		j;
	char	*buf;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		i++;
	while (--i > 0 && (j = -1))
		while (++j < i)
			if ((ft_strcmp(arr[i], arr[j]) < 0 && !reverse) ||
				(ft_strcmp(arr[i], arr[j]) > 0 && reverse))
			{
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
}

int			main(int argc, char **argv)
{
	t_ls	ls;
	char	**args;
	char	**files;
	char	**directories;
	int		i;

	(void)argc;
	ls_init(&ls);
	args = NULL;
	files = NULL;
	directories = NULL;
	if (!(args = options_parse(&ls, argv)))
		return (fail(&ls, args, files, directories));
	if (options_filter(args, &files, &directories))
		return (fail(&ls, args, files, directories));
	if (files && ls_printfiles(&ls, files))
		return (fail(&ls, args, files, directories));
	ft_strarr_sort(directories, ls.reverse);
	i = -1;
	ls.print_header |= ft_strarr_len(args) > 1;
	while (directories && directories[++i])
		if (ls_printdir(&ls, directories[i], files || i))
			return (fail(&ls, args, files, directories));
	cleanup_memory(&ls.dir, args, files, directories);
	return (0);
}
