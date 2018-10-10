/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 12:58:35 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:59:53 by jarcher     ###    #+. /#+    ###.fr     */
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
	t_uint8	height;
	t_uint8	width;
	char	map[104];
	char	*filename;
	t_tet	*tetriminos;
}				t_fillit;

int				parse_line(t_tet *tet, char *line, int nb);
t_tet			*parse_file(char *filename); // ok
t_tet			*add_tetriminos(t_tet **begin); // ok
t_tet			*reverse_tetriminos_list(t_tet **begin); // ok
t_uint8			get_tetriminos_bit(t_tet *tet, const t_uint8 height,
					const t_uint8 width);
t_uint8			solve(t_fillit *fillit);
void			display_map(t_fillit *fillit); // ok

#endif
