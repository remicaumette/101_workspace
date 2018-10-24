/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_toupper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/01 14:38:31 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/01 14:38:32 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	return ((c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c);
}
