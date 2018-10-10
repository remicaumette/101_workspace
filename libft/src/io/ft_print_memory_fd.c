/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_memory_fd.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 18:36:44 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 18:38:06 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static void	print_hex(unsigned char c, int fd)
{
	ft_putchar_fd((c / 16) >= 10 ? ((c / 16) + 'a' - 10)
		: ((c / 16) + '0'), fd);
	ft_putchar_fd((c % 16) >= 10 ? ((c % 16) + 'a' - 10)
		: ((c % 16) + '0'), fd);
}

static void	print_line(unsigned char *mem, size_t len, int fd)
{
	int i;
	int max;

	i = -1;
	max = (len > 16 ? 16 : len);
	while (++i < 16)
		if (i < max)
			ft_putchar_fd(ft_isprint(mem[i]) ? mem[i] : '.', fd);
		else
			ft_putchar_fd(' ', fd);
	ft_putchar_fd('\t', fd);
	i = -1;
	while (++i < 16)
	{
		if (i < max)
			print_hex(mem[i], fd);
		else
			ft_putchar_fd(' ', fd);
		if ((i + 1) % 2 == 0)
			ft_putchar_fd(' ', fd);
	}
	ft_putchar_fd('\n', fd);
}

void		ft_print_memory_fd(void *mem, size_t len, int fd)
{
	unsigned char	*memory;

	memory = (unsigned char *)mem;
	while (len > 0)
	{
		print_line(memory, len, fd);
		len -= (len > 16 ? 16 : len);
		memory += 16;
	}
}
