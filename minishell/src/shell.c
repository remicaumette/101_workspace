/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:08:10 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:06:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "coquillette.h"

int		coquille_init(t_coquille *coquille, char **environ)
{
	int		i;
	char	*tmp;

	i = -1;
	while (environ[++i])
		if (!(coquille->environ = ft_strarr_add(coquille->environ, environ[i])))
			return (1);
	tmp = coquille_obtenirenv(coquille, "HOME");
	if (!(coquille->maison = ft_strdup(tmp ? tmp : "/")))
		return (1);
	tmp = coquille_obtenirenv(coquille, "PWD");
	if (!(coquille->dossier_actuel = ft_strdup(tmp ? tmp : coquille->maison)))
		return (1);
	coquille->actuel = NULL;
	return (0);
}

void	coquille_detruire(t_coquille *coquille)
{
	if (coquille)
	{
		if (coquille->environ)
			ft_strarr_del(coquille->environ);
		if (coquille->maison)
			ft_strdel(&coquille->maison);
		if (coquille->dossier_actuel)
			ft_strdel(&coquille->dossier_actuel);
		if (coquille->ligne)
			ft_strdel(&coquille->ligne);
		if (coquille->actuel)
			cmd_detruire(coquille->actuel);
	}
}

int		coquille_evaluer(t_coquille *coquille)
{
	ft_putstr("$> ");
	while (get_next_line(0, &coquille->ligne))
	{
		if (cmd_depuis_ligne(coquille))
			return (1);
		
		// if (shell->current && cmd_run(shell, ))
		cmd_detruire(coquille->actuel);
		ft_strdel(&coquille->ligne);
		ft_putstr("$> ");
	}
	return (0);
}

char	*coquille_obtenirenv(t_coquille *coquille, char *var)
{
	int		i;
	char	*delimiter;

	(void)var;
	i = -1;
	while (coquille->environ[++i])
	{
		if (!(delimiter = ft_strchr(coquille->environ[i], '=')))
			continue ;
		if (ft_strnequ(coquille->environ[i], var, delimiter - coquille->environ[i]))
			return (delimiter + 1);
	}
	return (NULL);
}
