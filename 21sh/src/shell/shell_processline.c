/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_processline.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 13:06:27 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 19:10:28 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	debug(t_shell *shell)
{
	printf("=== TOKEN\n");
	print_token(shell->lexer->begin);
	printf("=== PARSER\n");
	printf("parser_parse = %d\n", parser_parse(shell->parser));
	print_node(shell->parser->root);
}

static char	**generate_env(t_command *command)
{
	int		i;
	char	**tmp;

	i = -1;
	if (!(tmp = ft_strarr_add(NULL, command->name)))
		return (NULL);
	while (command->arguments && command->arguments[++i])
		if (!(tmp = ft_strarr_add(tmp, command->arguments[i])))
			return (NULL);
	return (tmp);
}

int			shell_processline(t_shell *shell)
{
	t_process	*process;
	char		**env;

	debug(shell);
	if (!(env = generate_env(shell->parser->root->command)))
		return (1);
	if (shell->parser->root)
	{
		if (!(process = process_create(shell->parser->root->command->name,
			shell->parser->root->command->arguments, env)))
			return (1);
		if (process_run(process))
			return (1);
		process_destroy(process);
		ft_strarr_del(env);
	}
	return (0);
}
