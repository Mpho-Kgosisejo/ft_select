/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 23:00:26 by mkgosise          #+#    #+#             */
/*   Updated: 2017/09/20 14:11:03 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# include "../libft/libft.h"
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include <signal.h>

struct			s_display_args
{
	char	**selected;
	char	**args;
	int		max;
	int		i;
	int		x;
	int		y;
};

struct termios	*get_termios(struct termios *info);

void			move_pointer(char *action);
void			close_app(int is_esc);
void			interrupt_app(int signal);
void			window_change(int sig);
void			put_border(int size, char *str);
void			put_err_mssg(char *mssg);
void			resume_app(int sig);
void			pause_app(int sig);

char			**get_args(char **argv);
char			**get_selected(char **selected);

int				get_pointer(int new_pos);
int				ft_putc(int c);
int				canonical_on(void);
int				canonical_off(void);
int				key_triger(char *buf);
int				display_args(void);
int				is_dup(char *str);
int				get_max_col(void);
int				get_max_line(void);
int				get_win_size(int column);

#endif
