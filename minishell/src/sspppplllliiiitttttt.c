/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sspppplllliiiitttttt.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 13:32:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 15:52:14 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "coquillette.h"

static char	*fusionner_mot_avec_caractere(char **contenu, char c)
{
	char	s[2] = { c, 0 };
	char	*tmp;

	tmp = ft_strjoin(*contenu, s);
	ft_strdel(contenu);
	return (*contenu = tmp);
}

static char	*obtenir_mot_suivant(char ***mots, char *chaine)
{
	char	*mot;
	char	guillemet;

	mot = NULL;
	guillemet = -1;
	while (*chaine)
	{
		if (*chaine == ' ' && guillemet == -1)
		{
			if (mot)
				return (!(*mots = ft_strarr_add(*mots, mot)) ? NULL : chaine + 1);
			chaine++;
			continue ;
		}
		if (*chaine == guillemet)
			guillemet = -1;
		else if (*chaine == '"' || *chaine == '\'')
			guillemet = *chaine;
		else if (!(fusionner_mot_avec_caractere(&mot, *chaine)))
			return (NULL);
		chaine++;
	}
	printf("ok\n");
	if (!mot)
		return ("");
	return (!(*mots = ft_strarr_add(*mots, mot)) ? NULL : chaine);
}

char		**sil_te_plait_separe_ca(t_coquille *coquille)
{
	char	**mots;
	char	*actuel;

	mots = NULL;
	actuel = coquille->ligne;
	while (!!(actuel = obtenir_mot_suivant(&mots, actuel)) && *actuel)
		;
	return (!actuel ? NULL : mots);
}
