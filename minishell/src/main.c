/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:04 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 13:58:55 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "coquillette.h"

int	erreur(t_coquille *coquille)
{
	coquille_detruire(coquille);
	return (1);
}

int	main(int argc, char **argv, char **environ)
{
	t_coquille	coquille;

	(void)argc;
	(void)argv;
	if (coquille_init(&coquille, environ) || coquille_evaluer(&coquille))
		return (erreur(&coquille));
	coquille_detruire(&coquille);	
	return (0);
}
