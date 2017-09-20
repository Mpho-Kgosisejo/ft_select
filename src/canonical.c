/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canonical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 02:39:02 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 15:10:05 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

struct termios	*get_termios(struct termios *info)
{
	static struct termios	*ret;

	if (info == NULL)
	{
		if (!ret)
			return (NULL);
		return (ret);
	}
	return ((ret = info));
}

int				ft_putc(int c)
{
	return (write(2, &c, 1));
}

int				canonical_on(void)
{
	int				fd;
	struct termios	*info;

	fd = 2;
	info = get_termios(NULL);
	if (!isatty(fd))
		return (0);
	if (tgetent(NULL, getenv("TERM")) < 1 || tcgetattr(0, info) == -1)
		return (0);
	if (tcgetattr(fd, info))
		return (0);
	info->c_lflag &= ~(ICANON | ECHO);
	info->c_cc[VMIN] = 1;
	info->c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSANOW, info) == -1)
		return (0);
	return (1);
}

int				canonical_off(void)
{
	if (tcsetattr(2, TCSAFLUSH, get_termios(NULL)) == -1)
		return (0);
	return (1);
}
