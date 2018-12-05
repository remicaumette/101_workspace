/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sspppplllliiiitttttt.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 13:32:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 17:05:51 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoinc(char **mot, char c)
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

int			words_from_line(t_shell *shell, char ***words)
{
	char	*word;
	char	*line;
	char	quote;

	word = NULL;
	line = shell->line - 1;
	quote = -1;
	while (*++line)
	{
		if (((*line == ' ' || *line == '\t') && quote == -1) || *line == '"' || *line == '\'')
		{
			if (word)
			{
				if (!(*words = ft_strarr_add(*words, word)))
					return (1);
				ft_strdel(&word);
			}
			continue ;
		}
		if (!(ft_strjoinc(&word, *line)))
			return (1);
	}
	if (word)
	{
		if (!(*words = ft_strarr_add(*words, word)))
			return (1);
		ft_strdel(&word);
	}
	return (0);
}
