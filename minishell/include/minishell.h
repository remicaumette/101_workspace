/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:07:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 05:00:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <stdio.h>

typedef enum e_symbol	t_symbol;
typedef enum e_operator	t_operator;
typedef struct s_token	t_token;

enum e_symbol
{
	WORD,
	OPERATOR,
	NEWLINE,
};

enum e_operator
{
	NONE,
	AND_IF, // &&
	OR_IF, // ||
	DSEMI, // ;;
	DLESS, // <<
	DGREAT, // >>
	LESSAND, // <&
	GREATAND, // >&
	LESSGREAT, // <>
	DLESSDASH, // <<-
	CLOBBER, // >|
};

struct	s_token
{
	t_symbol	symbol;
	t_operator	op;
	char		*content;
	t_token		*prev;
	t_token		*next;
};

t_token		*token_create(t_symbol symbol, t_operator op, char *content);
void		token_destroy(t_token *token);
t_token		*lexer_tokenize(char *line);
#endif
