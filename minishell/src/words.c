/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   words.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:33:59 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 16:05:44 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			words_from_line(t_shell *shell, char ***words)
{
	char	*word;
	char	*line;
	char	quote;
	char	*tmp;

	word = NULL;
	line = shell->line - 1;
	quote = -1;
	while (*++line)
	{
		if ((*line == '"' || *line == '\'') && quote == -1)
			quote = *line;
		else if (*line == quote)
			quote = -1;
		else if ((*line == ' ' || *line == '\t') && quote == -1)
		{
			if (word)
			{
				if (!(*words = ft_strarr_add(*words, word)))
					return (1);
				ft_strdel(&word);
			}
		}
		else if (*line == '~' && quote == -1)
		{
			if (!(tmp = ft_strjoin(word, shell->home)))
				return (1);
			ft_strdel(&word);
			word = tmp;
		}
		else if (*line == '$' && (quote == '"' || quote == -1))
		{
			char	*name = NULL;

			while (*++line && (ft_isalnum(*line) || *line == '_'))
				if (!ft_strjoinc(&name, *line))
					return (1);
			line--;
			if (!name)
			{
				if (!(ft_strjoinc(&word, *line)))
					return (1);
				continue ;
			}
			char *env = shell_getenv(shell, name);
			if (env == NULL)
				env = "";
			if (!(tmp = ft_strjoin(word, env)))
				return (1);
			ft_strdel(&name);
			ft_strdel(&word);
			word = tmp;
		}
		else if (!(ft_strjoinc(&word, *line)))
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
