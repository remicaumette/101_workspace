/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lexer.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 16:37:01 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

typedef enum e_tokentype	t_tokentype;
typedef struct s_lexer		t_lexer;
typedef struct s_token		t_token;

enum						e_tokentype
{
	T_WORD,			// <word>
	T_NEWLINE,		// \n
	T_SQUOTE,		// '
	T_DQUOTE,		// "
	T_SEMI,			// ;
	T_PIPE,			// |
	T_ANDIF,		// &&
	T_ORIF,			// ||
	T_DSEMI,		// ;;
	T_DLESS,		// <<
	T_DGREAT,		// >>
	T_LESSAND,		// <&
	T_GREATAND,		// >&
	T_LESSGREAT,	// <>
	T_DLESSDASH,	// <<-
	T_CLOBBER,		// >|
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
	char			*content;
	t_token			*next;
};

t_lexer						*lexer_create(void);
void						lexer_cleanup(t_lexer *lexer);
void						lexer_destroy(t_lexer *lexer);
t_token						*lexer_addtoken(t_lexer *lexer,
	t_tokentype type, t_operatortype op, char *content);
void						lexer_deltoken(t_token *token);
t_tokentype					lexer_gettype(char *str);
t_operatortype				lexer_getop(char *str);
char						*ft_strjoinc(char **mot, char c);
int							lexer_tokenize(t_lexer *lexer, char *str);
#endif
