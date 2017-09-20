/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 04:04:06 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 08:07:51 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	text_standout(int standout, char *str, int index)
{
	if (standout)
	{
		if (is_dup(str))
		{
			ft_putstr_fd("\e[32m", 2);
			tputs(tgetstr("so", NULL), 1, ft_putc);
			if (index == get_pointer(-1))
				ft_putstr_fd("\e[33m", 2);
		}
	}
	else
	{
		if (is_dup(str))
		{
			ft_putstr_fd("\033[0m", 2);
			tputs(tgetstr("se", NULL), 1, ft_putc);
		}
	}
}

static void	text_underline(int underline, int index)
{
	if (underline)
	{
		if (index == get_pointer(-1))
		{
			ft_putstr_fd("\e[91m", 2);
			tputs(tgetstr("us", NULL), 1, ft_putc);
		}
	}
	else
	{
		if (index == get_pointer(-1))
		{
			ft_putstr_fd("\033[0m", 2);
			tputs(tgetstr("ue", NULL), 1, ft_putc);
		}
	}
}

int			display_args(void)
{
	struct s_display_args	st;

	st.i = -1;
	st.x = 0;
	st.y = 1;
	st.args = get_args(NULL);
	st.max = get_max_col() + 2;
	st.selected = get_selected(NULL);
	while (st.args[++st.i])
	{
		tputs(tgoto(tgetstr("cm", NULL), st.x, st.y), 1, ft_putc);
		text_underline(1, st.i);
		text_standout(1, st.args[st.i], st.i);
		ft_putstr_fd(st.args[st.i], 2);
		text_standout(0, st.args[st.i], st.i);
		text_underline(0, st.i);
		if ((st.x + (st.max + st.max)) < get_win_size(1))
			st.x += st.max;
		else
		{
			st.y++;
			st.x = 0;
		}
	}
	return (1);
}
