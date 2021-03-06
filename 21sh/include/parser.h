/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/14 08:35:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 16:35:05 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_shell			t_shell;
typedef enum e_nodetype			t_nodetype;
typedef struct s_parser			t_parser;
typedef struct s_node			t_node;
typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;

struct							s_parser
{
	t_shell		*shell;
	t_node		*root;
	t_token		*curr;
};

struct							s_node
{
	t_tokentype	type;
	t_command	*command;
	t_node		*next;
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
void							parser_cleanup(t_parser *parser);
void							parser_destroy(t_parser *parser);
int								parser_parse(t_parser *parser);
int								parser_expand(t_parser *parser);
t_node							*node_create(t_tokentype type,
	t_command *command);
void							node_destroy(t_node *node);
void							node_insert(t_node **root, t_node *node);
t_command						*command_create(char *name);
void							command_destroy(t_command *command);
t_redirection					*redirection_create(t_tokentype type,
	char *file, unsigned int in, unsigned int out);
void							redirection_destroy(t_redirection
	*redirection);
char							*parser_expandword(t_parser *parser,
	t_token *token);
t_command						*command_parse(t_parser *parser);
#endif
