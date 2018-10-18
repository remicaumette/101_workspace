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
		!(stats = ft_memalloc(sizeof(struct stat))) || lstat(filename, stats) ||
		!(passwd = getpwuid(stats->st_uid)) ||
		!(group = getgrgid(stats->st_gid)) ||
		!parse_permissions(info, stats) || !parse_date(info, stats) ||
		!(info->ssize = ft_lltoa(stats->st_size)) ||
		!(info->snlink = ft_itoa(stats->st_nlink)) ||
		!(info->user = ft_strdup(passwd->pw_name)) ||
		!(info->group = ft_strdup(group->gr_name)))
		return (NULL);
	info->left = NULL;
	info->right = NULL;
	info->nlink = stats->st_nlink;
	info->size = stats->st_size;
	ft_memdel((void **)&stats);
	return (info);
}

void		fileinfo_destroy(t_fileinfo **info)
{
	ft_strdel(&((*info)->filename));
	ft_strdel(&((*info)->permissions));
	ft_strdel(&((*info)->user));
	ft_strdel(&((*info)->group));
	ft_strdel(&((*info)->ssize));
	ft_strdel(&((*info)->snlink));
	ft_memdel((void **)info);
}

void		fileinfo_insert(t_fileinfo **node, t_fileinfo *info,
	sort_func cmp)
{
	if (!*node)
		*node = info;
	else if (cmp(info, *node) > 0)
		fileinfo_insert(&(*node)->left, info, cmp);
	else
		fileinfo_insert(&(*node)->right, info, cmp);
}

t_fileinfo	*fileinfo_last_right(t_fileinfo *node)
{
	if (!node->right)
		return (node);
	return (fileinfo_last_right(node->right));
}
