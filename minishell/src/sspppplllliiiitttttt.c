/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sspppplllliiiitttttt.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 13:32:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 13:44:03 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	**plz_split_this(t_shell *shell)
{
	char	**split;

	split = NULL;
	return (split = ft_strarr_add(split, shell->line));
}
