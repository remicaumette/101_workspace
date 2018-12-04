#include "minishell.h"

static char	*ft_strjoinc(char **content, char c)
{
	char	s[2] = { c, 0 };
	char	*tmp;

	tmp = ft_strjoin(*content, s);
	ft_strdel(content);
	return (*content = tmp);
}

static char	*get_word(char **content)
{
	char	*curr;
	char	*word;
	char	quote;

	curr = *content;
	word = NULL;
	quote = -1;
	while (*curr)
	{
		if (*curr == ' ' && quote == -1)
			break ;
		if (*curr == quote)
			quote = -1;
		else if (*curr == '"' || *curr == '\'')
			quote = *curr;
		else
			content = ft_strjoinc(&word, *curr);
		curr++;
	}
	*content = curr;
	return (word);
}

t_token		*lexer_tokenize(char *line)
{
	t_token		*curr;
	char		*content;

	prev = NULL;
	content = NULL;
	while (*line)
	{
		if (*line == ';')
			symbol = NEWLINE;
		else if (*line != ' ' || *line != '\t')
			curr = 
		line++;
	}
	curr = token_create(WORD, NONE, content);
	return (curr);
}
