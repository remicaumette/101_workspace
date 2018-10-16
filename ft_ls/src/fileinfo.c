/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fileinfo.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:52:49 by rcaumett    ###    #+. /#+    ###.fr     */
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
		!(stats = ft_memalloc(sizeof(struct stat))) ||
		stat(filename, stats) ||
		!(passwd = getpwuid(stats->st_uid)) ||
		!(group = getgrgid(stats->st_gid)))
		return (NULL);
	if (parse_permissions(info, stats) == 0 ||
		parse_date(info, stats) == 0)
		return (NULL);
	info->filename = filename;
	info->left = NULL;
	info->right = NULL;
	info->nlink = stats->st_nlink;
	info->user = passwd->pw_name;
	info->group = group->gr_name;
	info->size = stats->st_size;
	ft_memdel((void **)&stats);
	return (info);
}

void		fileinfo_destroy(t_fileinfo *info)
{
	ft_strdel(&(info->filename));
	ft_strdel(&(info->permissions));
	ft_memdel((void **)&info);
}

t_fileinfo	*fileinfo_insert(t_fileinfo **tree, t_fileinfo *info)
{
	(void)tree;
	(void)info;
	return (NULL);
}
