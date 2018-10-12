#ifndef IO_H
# define IO_H
# define BUFF_SIZE 1024
# include <unistd.h>


typedef struct	s_file
{
	int				fd;
	char			*content;
	struct s_file	*next;
}				t_file;

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
