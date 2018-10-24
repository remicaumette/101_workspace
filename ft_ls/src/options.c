/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   options.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:35:01 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 19:54:05 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	options_parse_flag(t_options *options, char c)
{
	if (c == 't')
		options->sort = sort_by_time;
	else if (c == 'S')
		options->sort = sort_by_size;
	else if (c == 'r')
		options->reverse = 1;
	else if (c == 'R')
		options->recursive = 1;
	else if (c == 'a')
		options->hidden = 1;
	else if (c == 'l')
		options->display = long_format_display;
	else if (c == '1')
		options->display = one_per_line_display;
	else if (c == 'C')
		options->display = one_per_line_display; //many_per_line
	else if (c == 'm')
		options->display = one_per_line_display; //with_commas
	else if (c == 'G')
		options->color = 1;
	else if (c == 'p')
		options->slash = 1;
	else
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putstr_fd("\nusage: ft_ls [-tSrRal1CmGp] [file ...]\n", 2);
		exit(1);
	}
}

static int	options_process_arg(t_options *options, char *arg, int *started)
{
	struct stat	stats;
	int			i;

	i = 0;
	*started |= arg[i] != '-';
	if (*started)
	{
		if (lstat(arg, &stats))
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
			return (1);
		}
		else
		{
			options->args = strarr_add(options->args, arg);
			options->args_count++;
		}
	}
	else
		while (arg[++i])
			options_parse_flag(options, arg[i]);
	return (0);
}

static int	options_process(t_options *options, char **argv)
{
	int	started;
	int	status;
	int	i;

	started = 0;
	status = 0;
	i = 0;
	while (argv[++i])
		status |= options_process_arg(options, argv[i], &started);
	strarr_sort(options->args, options->reverse);
	return (status);
}

int			options_init(t_options *options, char **argv)
{
	struct winsize	size;

	options->display = vertical_display;
	options->hidden = 0;
	options->color = 0;
	options->slash = 0;
	options->recursive = 0;
	options->reverse = 0;
	options->sort = sort_by_name;
	options->paths = NULL;
	options->paths_curr = 0;
	options->paths_count = 0;
	options->args = NULL;
	options->args_curr = 0;
	options->args_count = 0;
	ioctl(0, TIOCGWINSZ, &size);
	options->width = size.ws_col;
	options->width_curr = 0;
	return (options_process(options, argv));
}
