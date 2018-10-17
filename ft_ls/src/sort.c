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

int	sort_by_name(t_fileinfo *f1, t_fileinfo *f2)
{
	return (ft_strcmp(f1->filename, f2->filename) > 0);
}

int	sort_by_size(t_fileinfo *f1, t_fileinfo *f2)
{
	return (f1->size - f2->size);
}
