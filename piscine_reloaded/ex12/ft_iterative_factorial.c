/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_iterative_factorial.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:07:24 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 14:07:25 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int result;

	if (0 > nb || nb > 12)
		return (0);
	result = 1;
	while (nb)
		if (nb <= 1)
			result *= nb-- || 1;
		else
			result *= nb--;
	return (result);
}
