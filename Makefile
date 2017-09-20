# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 14:59:51 by mkgosise          #+#    #+#              #
#    Updated: 2017/09/20 15:16:23 by mkgosise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

RAWSRC = main.c			canonical.c		key_triger.c	globals.c\
		 display_args.c	move_pointer.c	is_dup.c		signals.c\
		 window_size.c	window_change_helper.c

SRC = $(RAWSRC:%=src/%)

OBJ = $(SRC:src/%.c=%.o)

LIBFT = ./libft/

FLAGS = #-Wall\
		-Wextra\
		-Werror

TERMCAP = -ltermcap

all: $(NAME)

$(NAME): $(SRC)
	@make -C $(LIBFT)
	@gcc -c $(FLAGS) $(SRC)
	gcc -g -o $(NAME) $(FLAGS) $(OBJ) -L$(LIBFT) -lft $(TERMCAP)

clean:
	@rm -f $(OBJ)
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean

re: fclean all
