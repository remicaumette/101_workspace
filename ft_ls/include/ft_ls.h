/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 15:27:16 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 18:54:54 by rcaumett    ###    #+. /#+    ###.fr     */
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
	vertical,
	long_format,
	one_per_line,
	many_per_line,
	with_commas,
}				t_display;

typedef enum	e_sort
{
	sort_name,
	sort_size,
	sort_time,
}				t_sort;

typedef struct	s_options
{
	t_display	display;
	t_sort		sort;
	int			reverse;
	int			recursive;
	int			hidden;
	char		**paths;
	int			paths_curr;
	int			paths_count;
	char		**args;
	int			args_curr;
	int			args_count;
}				t_options;

typedef struct	s_fileinfo
{
	char				*path;
	char				*filename;
	char				*nlink;
	char				*size;
	char				*link;
	char				*owner;
	char				*group;
	struct stat			*stats;
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

typedef int		(*t_sort_func)(t_fileinfo *, t_fileinfo *);

char			*path_join(char *path, char *filename);
char			**strarr_add(char **arr, char *elem);
void			strarr_sort(char **arr, int reverse);
void			strarr_del(char **arr);
void			stradd_formatted(char *str, char *content,
					int *cursor, int width);

int				options_init(t_options *options, char **argv);

t_fileinfo		*fileinfo_create(char *path, char *filename);
void			fileinfo_destroy(t_fileinfo **info);
void			fileinfo_recursive_destroy(t_fileinfo **info);
void			fileinfo_insert(t_options *options, t_fileinfo **node,
					t_fileinfo *info, t_sort_func cmp);
t_fileinfo		*fileinfo_last(t_fileinfo *node);

void			dirinfo_init(t_dirinfo *dir, char *path);
int				dirinfo_aggregate(t_dirinfo *dir, t_options *options);

t_sort_func		get_sort_func(t_sort sort);
int				sort_by_name(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_size(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_time(t_fileinfo *f1, t_fileinfo *f2);

void			one_per_line_display(t_options *options, t_fileinfo *file);
void			long_format_display(t_options *options, t_dirinfo *dir,
					t_fileinfo *file);
#endif
