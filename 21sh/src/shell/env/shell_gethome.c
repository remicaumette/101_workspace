/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_gethome.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:54:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 16:54:39 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char	*shell_gethome(t_shell *shell)
{
	char	*home;

	home = shell_getenv(shell, "HOME");
	return (home ? home : "/");
}
