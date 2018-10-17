/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:16 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 17:54:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

#include <stdio.h>

typedef struct	s_fileinfo
{
	char				*filename;
	char				*permissions;
	int					nlink;
	char				*snlink;
	char				*user;
	char				*group;
	long long			size;
	char				*ssize;
	char				*date_year;
	char				*date_month;
	char				*date_day;
	char				*date_hour;
	char				*date_min;
	struct s_fileinfo	*left;
	struct s_fileinfo	*right;
}				t_fileinfo;

typedef struct	s_dirinfo
{
	char				*cwd;
	int					total;
	int					total_dir;
	int					size_width;
	int					user_width;
	int					group_width;
	int					link_width;
	int					filename_width;
	t_fileinfo			*files;
	struct s_dirinfo	**dirs;
}				t_dirinfo;

int				parse_permissions(t_fileinfo *info, struct stat *stat);
int				parse_date(t_fileinfo *info, struct stat *stat);

t_fileinfo		*fileinfo_create(char *filename);
void			fileinfo_destroy(t_fileinfo **info);
void			fileinfo_recursive_destroy(t_fileinfo **info);
void			fileinfo_insert(t_fileinfo **node, t_fileinfo *info);

t_dirinfo		*dirinfo_create(char *cwd);
t_fileinfo		*dirinfo_aggregate(t_dirinfo *info, int aggregate_dir);
void			dirinfo_destroy(t_dirinfo **info);

int				sort_by_name(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_size(t_fileinfo *f1, t_fileinfo *f2);

void			long_format(t_dirinfo *info);
void			one_per_line_format(t_dirinfo *info);
void			many_per_line_format(t_dirinfo *info);
void			horizontal_format(t_dirinfo *info);
void			with_commas_format(t_dirinfo *info);

// Mon Oct 15 15:40:40 2018
// -rw-r--r--  1 rcaumett  student  9 Oct 15 15:40 auteur

// -rw-r--r--  1 rcaumett  student  9  Mon Oct 15 15:40:40 2018
//  auteur


/* The minimum width of a column is 3: 1 character for the name and 2
   for the separating white space.  */
#endif
