/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_triger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 03:25:24 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 15:06:05 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static char	*str_to_num(char *str)
{
	int		i;
	char	*tmp;
	char	*ret;

	i = 0;
	if (!(ret = ft_strnew(10)))
		return (NULL);
	while (str[i])
	{
		tmp = ft_itoa(str[i]);
		ft_strcat(ret, tmp);
		ft_strdel(&tmp);
		i++;
	}
	return (ret);
}

int			key_triger(char *buf)
{
	char	*tmp;

	if (!(tmp = str_to_num(buf)))
		return (0);
	if (ft_strcmp(tmp, "279165") == 0 || ft_strcmp(tmp, "279168") == 0)
		move_pointer("up");
	else if (ft_strcmp(tmp, "279166") == 0 || ft_strcmp(tmp, "279167") == 0)
		move_pointer("down");
	else if (ft_strcmp(tmp, "32") == 0)
		move_pointer("select");
	else if (ft_strcmp(tmp, "279151126") == 0 || ft_strcmp(tmp, "127") == 0)
		move_pointer("delete");
	else if (ft_strcmp(tmp, "27") == 0)
		return (-1);
	else
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}
