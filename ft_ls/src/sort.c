/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sort.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:26:49 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 17:06:09 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

sort_func	get_sort_func(t_sort sort)
{
	if (sort == sort_size)
		return sort_by_size;
	if (sort == sort_time)
		return sort_by_time;
	return (sort_by_name);
}

int			sort_by_name(t_fileinfo *f1, t_fileinfo *f2)
{
	return (ft_strcmp(f1->filename, f2->filename) > 0);
}

int			sort_by_size(t_fileinfo *f1, t_fileinfo *f2)
{
	int	i;

	i = f2->stats->st_size - f1->stats->st_size;
	return (i ? i : sort_by_name(f1, f2));
}

int			sort_by_time(t_fileinfo *f1, t_fileinfo *f2)
{
	int	i;

	i = f2->stats->st_mtime - f1->stats->st_mtime;
	return (i ? i : sort_by_name(f1, f2));
}
