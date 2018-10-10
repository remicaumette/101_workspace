/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strconv.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 13:01:25 by jarcher      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 13:01:29 by jarcher     ###    #+. /#+    ###.fr     */
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
