/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:16 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:54:41 by rcaumett    ###    #+. /#+    ###.fr     */
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
# include "libft.h"

typedef struct	s_fileinfo
{
	char				*filename;
	char				*permissions;
	int					nlink;
	char				*user;
	char				*group;
	long long			size;
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
	t_fileinfo			*files;
	struct s_dirinfo	**dirs;
}				t_dirinfo;

int				parse_permissions(t_fileinfo *info, struct stat *stat);
int				parse_date(t_fileinfo *info, struct stat *stat);

t_fileinfo		*fileinfo_create(char *filename);
void			fileinfo_destroy(t_fileinfo **info);
void			fileinfo_insert(t_fileinfo **node, t_fileinfo *info);

t_dirinfo		*dirinfo_create(char *cwd);
t_fileinfo		*dirinfo_aggregate(t_dirinfo *info, int aggregate_dir);
void			dirinfo_destroy(t_dirinfo **info);

#endif
