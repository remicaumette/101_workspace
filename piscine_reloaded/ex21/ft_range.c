/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_range.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:11:11 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 14:11:14 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *arr;
	int i;

	if (min >= max || (arr = (int *)malloc(sizeof(*arr) * (max - min))) == NULL)
		return (NULL);
	i = -1;
	while (++i < max - min)
		arr[i] = min + i;
	return (arr);
}
