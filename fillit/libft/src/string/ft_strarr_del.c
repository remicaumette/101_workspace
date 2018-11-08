/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_del.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/31 11:41:35 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 11:41:35 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarr_del(char **arr)
{
	int	i;

	i = -1;
	while (arr && arr[++i])
		ft_strdel(&arr[i]);
	ft_memdel((void **)&arr);
}
