/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   words.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:33:59 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/06 15:34:00 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		words_from_line(t_shell *shell, char ***words)
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
