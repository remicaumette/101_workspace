/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sspppplllliiiitttttt.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 13:32:28 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 17:05:51 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "coquillette.h"
/*
static int	obtenir_mot_suivant(char ***mots, char **mot, char **actuel)
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
	if (!mot)
		return ("");
	return (!(*mots = ft_strarr_add(*mots, mot)) ? NULL : chaine);
}
*/

static char	*mot_ajouter_caractere(char **mot, char c)
{
	char	*tmp;
	char	m[2];

	m[0] = c;
	m[1] = 0;
	if (!(tmp = ft_strjoin(*mot, m)))
		return (NULL);
	ft_strdel(mot);
	return (*mot = tmp);
}

char		**sil_te_plait_separe_ca(t_coquille *coquille)
{
	char	**words;
	char	*word;
	char	*line;
	char	quote;

	words = NULL;
	word = NULL;
	line = coquille->ligne - 1;
	quote = -1;
	while (*++line)
	{
		if ((*line == ' ' && quote == -1) || *line == '"' || *line == '\'')
		{
			if (word)
			{
				if (!(words = ft_strarr_add(words, word)))
					return (NULL);
				ft_strdel(&word);
			}
			continue ;
		}
		if (!(mot_ajouter_caractere(&word, *line)))
			return (NULL);
	}
	if (word)
	{
		if (!(words = ft_strarr_add(words, word)))
			return (NULL);
		ft_strdel(&word);
	}
	return (words);
}
