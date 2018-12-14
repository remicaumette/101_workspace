/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_sort.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 15:45:41 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 15:45:41 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarr_sort(char **arr, int reverse)
{
	int		i;
	int		j;
	char	*buf;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		i++;
	while (--i > 0 && (j = -1))
		while (++j < i)
			if ((ft_strcmp(arr[i], arr[j]) < 0 && !reverse) ||
				(ft_strcmp(arr[i], arr[j]) > 0 && reverse))
			{
				buf = arr[i];
				arr[i] = arr[j];
				arr[j] = buf;
			}
}
