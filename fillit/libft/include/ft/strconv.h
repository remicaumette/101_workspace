/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strconv.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/15 13:57:53 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 13:57:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRCONV_H
# define STRCONV_H
# include "std.h"

int			ft_atoi(const char *s);
char		*ft_itoa(int n);
long		ft_atol(const char *s);
char		*ft_ltoa(long n);
long long	ft_atoll(const char *s);
char		*ft_lltoa(long long n);
#endif
