# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyrode <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:19:00 by atyrode           #+#    #+#              #
#    Updated: 2017/09/30 18:45:04 by atyrode          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_SRC = ./srcs/
PATH_OBJ = ./
PATH_INC = ./includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ./includes/fractol.h

SRC =	fractol.c /
		color.c /
		image.c /
		julia.c /
		mandelbrot.c

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(addprefix $(PATH_SRC), $(SRC))
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
