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
# include "libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <sys/ioctl.h>

typedef enum	e_display
{
	vertical, // default
	long_format, // -l
	one_per_line, // -1
	many_per_line, // -C
	with_commas, // -m
}				t_display;

typedef enum	e_sort
{
	sort_name, // default
	sort_size, // -S
	sort_time, // -t
}				t_sort;

typedef struct	s_flags
{
	t_display	display;
	t_sort		sort;
	int			reverse; // -r
	int			recursive; // -R
	int			hidden; // -a
}				t_flags;

typedef struct	s_fileinfo
{
	char				*path;
	char				*filename;
	char				*nlink;
	char				*size;
	char				*link;
	struct stat			*stats;
	struct passwd		*passwd;
	struct group		*group;
	struct s_fileinfo	*left;
	struct s_fileinfo	*right;
}				t_fileinfo;

typedef struct	s_dirinfo
{
	char				*path;
	int					total;
	int					size_width;
	int					user_width;
	int					group_width;
	int					link_width;
	int					filename_width;
	t_fileinfo			*files;
}				t_dirinfo;

typedef			int (*sort_func)(t_fileinfo *, t_fileinfo *);

void			parse_flags(t_flags *flags, char **argv);
char			*path_join(char *path, char *filename);

t_fileinfo		*fileinfo_create(char *path, char *filename);
void			fileinfo_destroy(t_fileinfo **info);
void			fileinfo_recursive_destroy(t_fileinfo **info);
void			fileinfo_insert(t_flags *flags, t_fileinfo **node,
					t_fileinfo *info, sort_func cmp);
t_fileinfo		*fileinfo_last(t_fileinfo *node);

void			dirinfo_init(t_dirinfo *dir, char *path);
int				dirinfo_aggregate(t_dirinfo *dir, t_flags *flags);

sort_func		get_sort_func(t_sort sort);
int				sort_by_name(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_size(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_time(t_fileinfo *f1, t_fileinfo *f2);

void			one_per_line_display(t_flags *flags, t_fileinfo *file);
void			long_format_display(t_flags *flags, t_dirinfo *dir,
					t_fileinfo *file);
#endif
