/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 22:27:33 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_shell			t_shell;
typedef enum e_tokentype		t_tokentype;
typedef struct s_parser			t_parser;
typedef struct s_node			t_node;
typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;

struct							s_parser
{
	t_shell		*shell;
	t_node		*root;
};

struct							s_node
{
	t_node		*left;
	t_node		*right;
	t_tokentype	type;
	t_command	*command;
};

struct							s_command
{
	char			*name;
	char			**arguments;
	t_redirection	*redirection;
};

struct							s_redirection
{
	t_tokentype		type;
	char			*file;
	unsigned int	in;
	unsigned int	out;
	t_redirection	*next;
};

t_parser						*parser_create(t_shell *shell);
void							parser_destroy(t_parser *parser);
int								parser_expand(t_parser *parser);
t_node							*node_create(t_tokentype type,
	t_command *command);
void							node_destroy(t_node *node);
#endif
