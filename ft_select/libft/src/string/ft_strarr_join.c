/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strarr_join.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rcaumett <rcaumett@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/12 16:25:59 by rcaumett     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/12 18:18:15 by rcaumett    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strarr_join(char **arr, char *with)
{
	char	*tmp;
	char	*out;
	int		out_len;
	int		with_len;
	int		i;

	out = NULL;
	out_len = 0;
	with_len = ft_strlen(with);
	i = -1;
	while (with && arr && arr[++i])
	{
		if (!(tmp = ft_strnew(out_len + ft_strlen(arr[i]) +
			(i > 0 ? with_len : 0))))
			return (NULL);
		if (out)
		{
			ft_strcpy(tmp, out);
			ft_strdel(&out);
		}
		out = tmp;
		if (i > 0)
		{
			ft_strcpy(out + out_len, with);
			out_len += with_len;
		}
		ft_strcpy(out + out_len, arr[i]);
		out_len += ft_strlen(arr[i]);
	}
	return (out);
}
