/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 14:23:37 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 14:53:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

int		options_parse_flag(t_ls *ls, char c)
{
	if (c == 't')
		ls->sort = sort_by_time;
	else if (c == 'S')
		ls->sort = sort_by_size;
	else if (c == 'X')
		ls->sort = sort_by_extension;
	else if (c == 'r')
		ls->reverse = 1;
	else if (c == 'R')
		ls->recursive = 1;
	else if (c == 'a')
		ls->hidden = 1;
	else if (c == 'l')
		ls->display = long_format_display;
	else if (c == '1')
		ls->display = one_per_line_display;
	else if (c == 'm')
		ls->display = with_commas_display;
	else if (c == 'x')
		ls->display = horizontal_display;
	else if (c == 'p')
		ls->slash = 1;
	else
		return (1);
	return (0);
}

char	**options_printerr(char c)
{
	ft_putstr_fd("ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-tSXrRal1mxp] [file ...]\n", 2);
	return (NULL);
}

char	**options_parse(t_ls *ls, char **argv)
{
	char	**args;
	int		i;
	int		is_option;

	args = NULL;
	i = 0;
	is_option = 1;
	while (argv[++i])
		if (!*argv[i])
		{
			ft_putstr_fd("ls: fts_open: No such file or directory\n", 2);
			return (NULL);
		}
		else if ((is_option =
			(is_option ? (*argv[i] == '-' && argv[i][1]) : 0)))
		{
			if (ft_strequ(argv[i], "--") && !(is_option = 0))
				continue ;
			while (*++argv[i])
				if (options_parse_flag(ls, *argv[i]))
					return (options_printerr(*argv[i]));
		}
		else if (!(args = ft_strarr_add(args, argv[i])))
			return (NULL);
	return (!args && !(args = ft_strarr_add(args, ".")) ? NULL : args);
}

int		options_filter(char **args, char ***files, char ***directories)
{
	int			i;
	struct stat	stats;

	ft_strarr_sort(args, 0);
	i = -1;
	while (args[++i])
		if (!stat(args[i], &stats) || !lstat(args[i], &stats))
		{
			if (S_ISDIR(stats.st_mode))
				if (!(*directories = ft_strarr_add(*directories, args[i])))
					return (1);
			if (!S_ISDIR(stats.st_mode))
				if (!(*files = ft_strarr_add(*files, args[i])))
					return (1);
		}
		else
			ls_printerror(args[i]);
	return (0);
}
