/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:20:42 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 14:12:27 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void		interrupt_app(int sig)
{
	sig = sig + 0;
	close_app(1);
}

void		pause_app(int sig)
{
	sig = sig + 0;
	if (!canonical_off())
	{
		ft_putendl_fd("Error turning canonical mode off", 2);
		ft_putendl_fd("Program faild to pause", 2);
		close_app(1);
	}
}

void		resume_app(int sig)
{
	sig = sig + 0;
	if (!canonical_on())
	{
		ft_putendl_fd("Error turning on canonical mode", 2);
		ft_putendl_fd("Program faild to resume", 2);
		close_app(1);
	}
}

void		window_change(int sig)
{
	int		col;
	int		line;
	char	*border_char;

	if (tgetent(NULL, getenv("TERM")) <= 0)
		return ;
	if ((col = tgetnum("co")) == -1 ||
			(line = tgetnum("li")) == -1)
		return ;
	sig = sig + 0;
	border_char = "-";
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	put_border(col, border_char);
	if (get_max_col() > col)
		put_err_mssg("!-- Width too small --!");
	else if (get_max_line() + 2 > line)
		put_err_mssg("!-- Hieght too small --!");
	else
		display_args();
	ft_putstr_fd("\n", 2);
	put_border(col, border_char);
}
