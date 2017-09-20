/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 22:59:29 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 15:41:01 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static int	init(char **args, struct termios *info)
{
	get_termios(info);
	if (!canonical_on())
	{
		ft_putendl_fd("Error turning on canonical mode", 2);
		return (0);
	}
	get_args(args);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("cl", NULL), 1, ft_putc);
	signal(SIGINT, interrupt_app);
	signal(SIGKILL, interrupt_app);
	signal(SIGABRT, interrupt_app);
	signal(SIGSTOP, pause_app);
	signal(SIGCONT, resume_app);
	signal(SIGWINCH, window_change);
	return (1);
}

void		close_app(int is_esc)
{
	int		i;
	char	**selected;

	tputs(tgetstr("ve", NULL), 1, ft_putc);
	tputs(tgetstr("te", NULL), 1, ft_putc);
	if (!canonical_off())
		ft_putendl_fd("Error truning off canonical mode", 2);
	if (!is_esc)
	{
		i = 0;
		if ((selected = get_selected(NULL)))
			while (selected[i])
			{
				ft_putstr_fd(selected[i], 1);
				if (selected[i + 1])
					ft_putstr_fd(" ", 1);
				i++;
			}
	}
	ft_free2d((void**)get_selected(NULL));
	ft_free2d((void**)get_args(NULL));
	exit(1);
}

int			main(int argc, char *argv[])
{
	int				rd;
	char			buf[4];
	struct termios	info;

	if (argc > 1)
	{
		if (!init(&argv[1], &info))
			exit(1);
		while (-42)
		{
			window_change(0);
			ft_bzero((void*)buf, 4);
			rd = read(0, buf, 4);
			buf[rd] = 0;
			if (buf[0] == '\n')
				close_app(0);
			if (key_triger(buf) == -1)
				break ;
		}
		close_app(1);
	}
	return (0);
}
