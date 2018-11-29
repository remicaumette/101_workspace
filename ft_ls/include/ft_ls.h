/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ls.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 16:37:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 15:34:07 by rcaumett    ###    #+. /#+    ###.fr     */
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
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <stdio.h>

typedef struct	s_fileinfo
{
	char				*path;
	char				*filename;
	char				*nlink;
	char				*size;
	char				*minor;
	char				*link;
	char				*owner;
	char				*group;
	struct stat			*stats;
	struct s_fileinfo	*next;
}				t_fileinfo;

typedef struct	s_dirinfo
{
	char		*path;
	int			total;
	int			size_width;
	int			user_width;
	int			group_width;
	int			link_width;
	int			filename_width;
	int			files_count;
	t_fileinfo	*files;
}				t_dirinfo;

typedef struct	s_ls
{
	int			slash;
	int			reverse;
	int			recursive;
	int			hidden;
	int			term_width;
	int			print_header;
	void		(*display)(struct s_ls *);
	int			(*sort)(t_fileinfo *, t_fileinfo *);
	t_dirinfo	dir;
}				t_ls;

void			ls_init(t_ls *ls);
void			ls_printerror(char *filename);
int				ls_printfiles(t_ls *ls, char **files);
int				ls_printdir(t_ls *ls, char *dir, int println);

int				options_parse_flag(t_ls *ls, char c);
char			**options_parse(t_ls *ls, char **argv);
int				options_filter(char **args, char ***files, char ***directories);

void			dirinfo_insert_file(t_ls *ls, t_fileinfo *file);
int				dirinfo_init(t_ls *ls, char *path);
int				dirinfo_aggregate(t_ls *ls, char ***directories);
void			dirinfo_destroy(t_dirinfo *dir);

t_fileinfo		*fileinfo_create(char *path, char *filename);
void			fileinfo_destroy(t_fileinfo **file);
void			fileinfo_insert(t_ls *ls, t_fileinfo *file);

int				sort_by_name(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_size(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_time(t_fileinfo *f1, t_fileinfo *f2);
int				sort_by_extension(t_fileinfo *f1, t_fileinfo *f2);

void			one_per_line_display(t_ls *ls);
void			long_format_display(t_ls *ls);
void			with_commas_display(t_ls *ls);
void			horizontal_display(t_ls *ls);
void			vertical_display(t_ls *ls);

char			*path_join(char *path, char *filename);
char			*file_readlink(char *path, struct stat *stats);
void			stradd_formatted_left(char *str, char *content,
	int *cursor, int width);
void			stradd_formatted_right(char *str, char *content,
	int *cursor, int width);
char			file_type(struct stat *stats);
void			ft_strarr_sort(char **arr, int reverse);
#endif
