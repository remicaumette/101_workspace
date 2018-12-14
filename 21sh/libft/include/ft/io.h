/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   io.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 15:07:37 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 15:07:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H
# define BUFF_SIZE 4096
# include <unistd.h>

typedef struct	s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}				t_gnl;

int				get_next_line(const int fd, char **line);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(char const *s);
void			ft_print_memory_fd(void *mem, size_t len, int fd);
void			ft_print_memory(void *mem, size_t len);
#endif
