/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 12:13:39 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/19 13:22:38 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		get_max_line(void)
{
	int	i;
	int	x;
	int	y;
	int	max;
	int	col;

	i = 0;
	x = 0;
	y = 0;
	col = get_win_size(1);
	max = get_max_col() + 2;
	while (get_args(NULL)[i])
	{
		if ((x + (max + max)) < col)
			x += max;
		else
		{
			y++;
			x = 0;
		}
		i++;
	}
	return (y + 1);
}

int		get_max_col(void)
{
	int		i;
	int		l;
	int		ret;
	char	**args;

	i = 0;
	ret = 0;
	args = get_args(NULL);
	while (args[i])
	{
		if ((l = ft_strlen(args[i])) > ret)
			ret = l;
		i++;
	}
	return (ret);
}

int		get_win_size(int colu)
{
	int col;
	int line;

	if (tgetent(NULL, getenv("TERM")) <= 0)
		return (-1);
	col = 0;
	line = 0;
	if (colu)
	{
		if ((col = tgetnum("co")) == -1)
			return (-1);
		return (col);
	}
	else
	{
		if ((line = tgetnum("li")) == -1)
			return (-1);
		return (line);
	}
}
