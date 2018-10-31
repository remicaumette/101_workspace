/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   with_commas.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/24 15:34:29 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 15:56:12 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

void	with_commas_display(t_options *options, t_dirinfo *dir,
	t_fileinfo *file, t_fileinfo *last)
{
	int		len;
	char	separator;

	(void)dir;
	(void)last;
	len = ft_strlen(file->filename);
	if (options->width_curr)
	{

		if (options->width_curr + len + 3 < options->width &&
			options->width_curr <= options->width - len - 2)
		{
			options->width_curr += (len + 2);
			separator = ' ';
		}
		else
		{
			options->width_curr = 0;
			separator = '\n';
		}
		ft_putchar(',');
		ft_putchar(separator);
	}
	else
		options->width_curr += len;
	ft_putstr(file->filename);
	if (file == last)
		ft_putchar('\n');
}
