/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 15:49:44 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/18 08:07:33 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		is_dup(char *str)
{
	int		i;
	char	**select;

	i = 0;
	select = get_selected(NULL);
	if (!select)
		return (0);
	while (select[i])
	{
		if (ft_strcmp(str, select[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
