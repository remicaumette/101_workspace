#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <sys/stat.h>

typedef struct	s_btree_file
{
	char				*filename;
	struct stat			*stat;
	struct s_btree_file	*left;
	struct s_btree_file	*right;
}				t_btree_file;
#endif
