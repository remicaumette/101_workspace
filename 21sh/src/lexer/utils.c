/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 15:30:38 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_tokentype		lexer_gettype(char *str)
{
	if (lexer_getop(str))
		return (OPERATOR);
	else if (*str == '\n' || *str == ';')
		return (NEWLINE);
	return (WORD);
}

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
	if (ft_strnequ(str, "|", 1))
		return (PIPE);
	return (NONE);
}

char			*ft_strjoinc(char **mot, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = ft_strjoin(*mot, m)))
		return (NULL);
	ft_strdel(mot);
	return (*mot = tmp);
}
