/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   with_commas.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 02:42:44 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_seperator(t_options *options, t_fileinfo *file)
{
	int		min;
	int		len;
	char	separator;

	min = 2 + options->slash && S_ISDIR(file->stats->st_mode);
	if ((len = ft_strlen(file->filename)) && options->width_curr)
	{
		if (options->width_curr + len + min < options->width)
		{
			options->width_curr += (len + min);
			separator = ' ';
		}
		else
		{
			options->width_curr = len + min;
			separator = '\n';
		}
		ft_putchar(',');
		ft_putchar(separator);
	}
	else
		options->width_curr += len + min;
}

void		with_commas_display(t_options *options, t_dirinfo *dir,
	t_fileinfo *file, t_fileinfo *last)
{
	(void)last;
	(void)dir;
	print_seperator(options, file);
	ft_putstr(file->filename);
	if (options->slash && S_ISDIR(file->stats->st_mode))
		ft_putchar('/');
	if (file == last)
	{
		ft_putchar('\n');
		options->width_curr = 0;
	}
}
