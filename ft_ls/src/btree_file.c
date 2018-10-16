/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btree_file.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 17:16:17 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 17:28:21 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_btree_file	*btree_file_create(char *filename)
{
	t_btree_file	*file;

	if (!(file = (t_btree_file *)ft_memalloc(sizeof(*file))))
		return (NULL);
	file->filename = filename;
	file->left = NULL;
	file->right = NULL;
	if (!(file->stat = (struct stat *)ft_memalloc(sizeof(*(file->stat)))))
		return (NULL);
	file->group = NULL;
	file->passwd = NULL;
	return (file);
}

void			btree_file_insert(t_btree_file **begin, int cmp(t_btree_file ), t_btree_file *file)
{
	(void)begin;
	(void)cmp;
	(void)file;
}
