#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberezyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 14:34:40 by lberezyn          #+#    #+#              #
#    Updated: 2017/12/05 14:34:46 by lberezyn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC = ./src/main.c \
	  ./src/draw.c \
	  ./src/hooks.c \
	  ./src/mouse.c \
	  ./src/fractals.c \
	  ./src/fractals2.c \
	  ./src/iters.c

OFILES = draw.o main.o hooks.o mouse.o fractals.o fractals2.o iters.o

FLAG = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o : %.c include/fractol.h
	gcc $(FLAGS) -o $@ -c $<

$(OFILES): $(SRC) include/fractol.h
	gcc -Wall -Werror -Wextra -c $(SRC)

$(NAME):  $(OFILES) include/fractol.h
	make -C libft
	@gcc $(FLAG) $(OFILES) -o $(NAME) -L./libft -lft
	@echo "$(NAME) SUCCESSFULLY compiled"

clean:
	/bin/rm -f $(OFILES)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re