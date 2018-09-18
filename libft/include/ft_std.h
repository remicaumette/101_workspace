#ifndef FT_STD_H
# define FT_STD_H
# include <stdlib.h>

int		ft_atoi(const char *s);
void	ft_bzero(void *mem, size_t size);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
#endif