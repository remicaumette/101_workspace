/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:58:35 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 11:17:03 by jarcher     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define USAGE "usage: ./fillit filename\n"
# define ERROR "error\n"
# include "libft.h"
# include <fcntl.h>

typedef unsigned char	t_uint8;

typedef struct	s_tet
{
	char			letter;
	t_uint8			height;
	t_uint8			width;
	t_uint8			content[2];
	struct s_tet	*next;
}				t_tet;

typedef struct	s_fillit
{
	t_uint8	size;
	char	*map;
	char	*filename;
	t_tet	*tetriminos;
}				t_fillit;

t_tet			*parse_file(char *filename);
t_tet			*add_tetriminos(t_tet **begin);
t_tet			*reverse_tetriminos_list(t_tet **begin);
t_uint8			get_tetriminos_bit(t_tet *tet, const t_uint8 height,
					const t_uint8 width);
t_uint8			solve(t_fillit *fillit);

#endif
