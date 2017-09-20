/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 03:47:17 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 14:56:06 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

char	**get_args(char **args)
{
	static char **ret;

	if (args == NULL)
	{
		if (ret == NULL)
			return (NULL);
		return (ret);
	}
	return ((ret = ft_listdup(args)));
}

char	**get_selected(char **selected)
{
	static char **ret;

	if (selected == NULL)
	{
		if (ret == NULL)
			return (NULL);
		return (ret);
	}
	return ((ret = selected));
}

int		get_pointer(int new_pos)
{
	static int	pointer;

	if (new_pos == -1)
		return (pointer);
	return ((pointer = new_pos));
}
