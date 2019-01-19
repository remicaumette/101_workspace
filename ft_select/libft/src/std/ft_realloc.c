/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:22:32 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/10 13:43:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	if (size <= 0)
		return (NULL);
	if (!(tmp = ft_memalloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(tmp, ptr, size);
		ft_memdel(&ptr);
	}
	return (tmp);
}
