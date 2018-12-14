/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 10:03:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 15:24:12 by rcaumett    ###    #+. /#+    ###.fr     */
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

static char		*ft_strjoinc(char **mot, char c)
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

unsigned int	lexer_isop(char *str)
{
	return (ft_strnequ(str, "&&", 2) || ft_strnequ(str, "||", 2) ||
		ft_strnequ(str, ";;", 2) || ft_strnequ(str, "<<", 2) ||
		ft_strnequ(str, ">>", 2) || ft_strnequ(str, ">>", 2) ||
		ft_strnequ(str, "<&", 2) || ft_strnequ(str, ">&", 2) ||
		ft_strnequ(str, "<>", 2) || ft_strnequ(str, "<<-", 3) ||
		ft_strnequ(str, ">|", 2) || ft_strnequ(str, ";", 2));
}

unsigned int	lexer_getword(char *str, char **word)
{
	char	*tmp;
	char	quote;

	tmp = str - 1;
	quote = -1;
	while (*++tmp)
	{
		if ((*tmp == '\t' || *tmp == ' ' || *tmp == '\\' || lexer_isop(str)) && quote == -1)
			break ;
		else if ((*tmp == '\'' || *tmp == '"') && quote == -1)
			quote = *tmp;
		else if (quote != -1 && *tmp == quote)
			quote = -1;
		else if (!(ft_strjoinc(word, *tmp)))
			return (0);
	}
	return (tmp - str);
}
