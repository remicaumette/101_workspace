/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   words.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/06 15:33:59 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 18:05:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int	words_env(t_word *word)
{
	while (*++word->line && (ft_isalnum(*word->line) || *word->line == '_'))
		if (!ft_strjoinc(&word->name, *word->line))
			return (1);
	word->line--;
	if (!word->name)
	{
		if (!(ft_strjoinc(&word->word, *word->line)))
			return (1);
		return (0);
	}
	word->env = shell_getenv(word->shell, word->name);
	if (word->env == NULL)
		word->env = "";
	if (!(word->tmp = ft_strjoin(word->word, word->env)))
		return (1);
	ft_strdel(&word->name);
	ft_strdel(&word->word);
	word->word = word->tmp;
	return (0);
}

static int	words_checks(t_word *word)
{
	if ((*word->line == '"' || *word->line == '\'') && word->quote == -1)
		word->quote = *word->line;
	else if (*word->line == word->quote)
		word->quote = -1;
	else if ((*word->line == ' ' || *word->line == '\t') && word->quote == -1)
	{
		if (word->word)
		{
			if (!(*word->words = ft_strarr_add(*word->words, word->word)))
				return (1);
			ft_strdel(&word->word);
		}
	}
	else if (*word->line == '~' && word->quote == -1)
	{
		if (!(word->tmp = ft_strjoin(word->word, word->shell->home)))
			return (1);
		ft_strdel(&word->word);
		word->word = word->tmp;
	}
	else
		return (0);
	return (2);
}

static int	words_run(t_word *word)
{
	int	i;

	while (*++word->line)
		if ((i = words_checks(word)))
		{
			if (i == 1)
				return (1);
		}
		else if (*word->line == '$' &&
			(word->quote == '"' || word->quote == -1))
		{
			if (words_env(word))
				return (1);
		}
		else if (!(ft_strjoinc(&word->word, *word->line)))
			return (1);
	if (word->word)
	{
		if (!(*word->words = ft_strarr_add(*word->words, word->word)))
			return (1);
		ft_strdel(&word->word);
	}
	return (0);
}

int			words_from_line(t_shell *shell, char ***words)
{
	t_word	word;

	word.shell = shell;
	word.words = words;
	word.word = NULL;
	word.tmp = NULL;
	word.env = NULL;
	word.name = NULL;
	word.line = shell->line - 1;
	word.quote = -1;
	return (words_run(&word));
}
