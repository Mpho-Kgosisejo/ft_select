/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 04:15:06 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 14:57:28 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	insert_selected(int index)
{
	char **selected;
	char **tmp;

	if (get_selected(NULL) == NULL)
		tmp = ft_listnew(0);
	else
		tmp = get_selected(NULL);
	if (!is_dup(get_args(NULL)[index]))
	{
		selected = ft_listcat(tmp, get_args(NULL)[index]);
		ft_free2d((void**)tmp);
		get_selected(selected);
	}
	else
	{
		if (get_selected(NULL))
			ft_list_del_el(get_selected(NULL), get_args(NULL)[index]);
	}
	move_pointer("down");
}

static void	remove_selected(char *str)
{
	int		i;
	char	**args;

	args = get_args(NULL);
	if (args)
	{
		if (is_dup(str))
		{
			ft_list_del_el(get_selected(NULL), str);
		}
		i = 0;
		while (args[i])
		{
			if (ft_strcmp(args[i], str) == 0)
			{
				ft_list_del_el(args, str);
				break ;
			}
			i++;
		}
		if (!countlist(args))
			close_app(1);
	}
	move_pointer("up");
}

void		move_pointer(char *action)
{
	int		list_max;

	list_max = countlist(get_args(NULL));
	if (ft_strcmp("up", action) == 0)
	{
		if (get_pointer(-1) > 0)
			get_pointer(get_pointer(-1) - 1);
		else
			get_pointer(list_max - 1);
	}
	else if (ft_strcmp("down", action) == 0)
	{
		if (get_pointer(-1) < (list_max - 1))
			get_pointer(get_pointer(-1) + 1);
		else
			get_pointer(0);
	}
	else if (ft_strcmp("select", action) == 0)
		insert_selected(get_pointer(-1));
	else if (ft_strcmp("delete", action) == 0)
		remove_selected(get_args(NULL)[get_pointer(-1)]);
}
