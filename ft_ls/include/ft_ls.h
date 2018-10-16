#ifndef FT_LS_H
# define FT_LS_H
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/stat.h>
# include "libft.h"

typedef struct	s_btree_file
{
	char				*filename;
	struct stat			*stat;
	struct passwd		*passwd;
	struct group		*group;
	struct s_btree_file	*left;
	struct s_btree_file	*right;
}				t_btree_file;

typedef struct	s_ls
{
	int				is_root;
	int				total;
	char			*folder;
	t_btree_file	*file;
}				t_ls;

char			*get_permissions(struct stat *stat);
char			*get_date(struct stat *stat);
t_btree_file	*btree_file_create(char *filename);
#endif
