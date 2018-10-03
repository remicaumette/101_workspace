/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 19:51:42 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 15:08:27 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFF_SIZE 8
# include "libft.h"

typedef struct	s_file
{
	int				fd;
	unsigned char	status;
	char			*content;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);
#endif
