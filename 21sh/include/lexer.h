/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 10:50:54 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tokentype	t_tokentype;
typedef enum e_operatortype	t_operatortype;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;

enum						e_tokentype
{
	WORD,
	OPERATOR,
	NEWLINE,
	IO_NUMBER,
};

enum						e_operatortype
{
	NONE,
	AND_IF,		// &&
	OR_IF,		// ||
	DSEMI,		// ;;
	DLESS,		// <<
	DGREAT,		// >>
	LESSAND,	// <&
	GREATAND,	// >&
	LESSGREAT,	// <>
	DLESSDASH,	// <<-
	CLOBBER,	// >|
};

struct						s_lexer
{
	t_token			*begin;
	t_token			*end;
	unsigned int	count;
};

struct						s_token
{
	t_tokentype		type;
	t_operatortype	op;
	char			*content;
	t_token			*next;
};

t_lexer						*lexer_create();
void						lexer_destroy(t_lexer *lexer);
t_token						*lexer_addtoken(t_lexer *lexer,
	t_tokentype type, t_operatortype op, char *content);
void						lexer_deltoken(t_token *token);
int							lexer_tokenize(t_lexer *lexer, char *str);
t_operatortype				lexer_getop(char *str);
int							lexer_tokenlen(t_token *token);
#endif
