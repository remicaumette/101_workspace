/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/03 05:14:12 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:11:20 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "coquillette.h"

int		cmd_depuis_ligne(t_coquille *coquille)
{
	char	**split;

	if (!(split = sil_te_plait_separe_ca(coquille)))
		return (1);
	for (int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	return (0);
}

void	cmd_detruire(t_cmd *cmd)
{
	t_cmd	*curr;
	t_cmd	*suivant;

	suivant = cmd;
	while (suivant)
	{
		curr = suivant;
		suivant = curr->suivant;

		if (curr->cmd)
			ft_strdel(&curr->cmd);
		if (curr->args)
			ft_strarr_del(curr->args);
		ft_memdel((void **)&curr);
	}
}
