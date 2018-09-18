#include "ft_io.h"

static void	put_digit(int n, int fd)
{
	if (n >= 10 || n <=  -10)
		put_digit(n / 10, fd);
	ft_putchar_fd((n < 0 ? -(n % 10) : (n % 10)) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	put_digit(n , fd);
}