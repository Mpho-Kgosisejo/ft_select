/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_change_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 08:08:31 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 08:14:01 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	put_border(int size, char *str)
{
	ft_putstr_fd("\e[90m", 2);
	while (size)
	{
		ft_putstr_fd(str, 2);
		size--;
	}
	ft_putstr_fd("\033[0m", 2);
}

void	put_err_mssg(char *mssg)
{
	ft_putstr_fd("\e[31m", 2);
	ft_putstr_fd(mssg, 2);
	ft_putstr_fd("\e[90m", 2);
}
