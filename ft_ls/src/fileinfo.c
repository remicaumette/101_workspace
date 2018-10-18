/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fileinfo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 18:00:28 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_ls.h"

t_fileinfo	*fileinfo_create(char *filename)
{
	t_fileinfo		*info;
	struct stat		*stats;
	struct passwd	*passwd;
	struct group	*group;

	if (!(info = ft_memalloc(sizeof(t_fileinfo))) ||
		!(info->filename = ft_strdup(filename)) ||
		!(stats = ft_memalloc(sizeof(struct stat))) ||
		lstat(filename, stats) ||
		!(passwd = getpwuid(stats->st_uid)) ||
		!(group = getgrgid(stats->st_gid)) ||
		!(info->size = ft_lltoa(stats->st_size)) ||
		!(info->nlink = ft_itoa(stats->st_nlink)))
		return (NULL);
	info->left = NULL;
	info->right = NULL;
	return (info);
}

void		fileinfo_destroy(t_fileinfo **info)
{
	ft_strdel(&((*info)->filename));
	ft_strdel(&((*info)->size));
	ft_strdel(&((*info)->nlink));
	ft_memdel((void **)&((*info)->stats));
	ft_memdel((void **)info);
}

void		fileinfo_recursive_destroy(t_fileinfo **info)
{
	if ((*info)->right)
		fileinfo_recursive_destroy(&(*info)->right);
	if ((*info)->left)
		fileinfo_recursive_destroy(&(*info)->left);
	fileinfo_destroy(info);
}

void		fileinfo_insert(t_flags *flags, t_fileinfo **node, t_fileinfo *info,
	sort_func cmp)
{
	if (!*node)
		*node = info;
	else if (cmp(info, *node) > 0)
		fileinfo_insert(flags, &(*node)->left, info, cmp);
	else
		fileinfo_insert(flags, &(*node)->right, info, cmp);
}

t_fileinfo	*fileinfo_last(t_fileinfo *node)
{
	if (!node->right)
		return (node);
	return (fileinfo_last(node->right));
}
