/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coquillette.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/02 19:07:50 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:04:08 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COQUILLETTE_H
# define COQUILLETTE_H
# include "libft.h"
# include <stdio.h>

typedef struct s_cmd		t_cmd;
typedef struct s_coquille	t_coquille;

struct					s_cmd
{
	char	*cmd;
	char	**args;
	int		status;
	t_cmd	*suivant;
};

struct					s_coquille
{
	char	**environ;
	char	*maison;
	char	*dossier_actuel;
	char	*ligne;
	t_cmd	*actuel;
};

int							coquille_init(t_coquille *coquille, char **environ);
void						coquille_detruire(t_coquille *coquille);
int							coquille_evaluer(t_coquille *coquille);
char						*coquille_obtenirenv(t_coquille *coquille, char *var);

int							cmd_depuis_ligne(t_coquille *coquille);
void						cmd_detruire(t_cmd *cmd);

char						**sil_te_plait_separe_ca(t_coquille *coquille);
#endif
