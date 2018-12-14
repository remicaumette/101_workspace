/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   operator.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 10:55:46 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_operatortype	lexer_getop(char *str)
{
	if (ft_strnequ(str, "&&", 2))
		return (AND_IF);
	if (ft_strnequ(str, "||", 2))
		return (OR_IF);
	if (ft_strnequ(str, ";;", 2))
		return (DSEMI);
	if (ft_strnequ(str, "<<", 2))
		return (DLESS);
	if (ft_strnequ(str, ">>", 2))
		return (DGREAT);
	if (ft_strnequ(str, "<&", 2))
		return (LESSAND);
	if (ft_strnequ(str, ">&", 2))
		return (GREATAND);
	if (ft_strnequ(str, "<>", 2))
		return (LESSGREAT);
	if (ft_strnequ(str, "<<-", 3))
		return (DLESSDASH);
	if (ft_strnequ(str, ">|", 2))
		return (CLOBBER);
	return (NONE);
}
