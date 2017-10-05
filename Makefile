# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyrode <atyrode@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:19:00 by atyrode           #+#    #+#              #
#    Updated: 2017/10/05 19:02:39 by atyrode          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

PATH_OBJ = ./
PATH_INC = ./includes/

CC = clang
CFLAGS = -Wall -Wextra -Werror

SRC =	srcs/fractol.c \
		srcs/image.c \
		srcs/newjuliabrot.c \
		srcs/window.c \
		srcs/draw_gpu_fractal.c \
		srcs/load_gpu_sources.c \
		srcs/opencl_init.c \
		srcs/colors.c \
		srcs/main.c \
		srcs/hook.c

O_FILES = $(SRC:.c=.o)
MLX_LIB = -L/usr/local/lib -lmlx -L. ./minilibx_macos/libmlx.a -framework OpenGL -framework Appkit
MLX_I   = -I/usr/local/include

LIBFT_L = -Llibft -lft
LIBFT_I = -Ilibft -Iincludes -Iminilibx_macos/mlx.h

# Enables precision double output

PRECISION = -DPRECISION

SPECIAL =

all: make_libft $(NAME)

#makeautoheader:
#	./genautoheader output.h $(SRC)

make_libft:
	make -C libft

#$(NAME): makeautoheader $(O_FILES)
$(NAME): $(O_FILES)
	$(CC) $(CC_FLAGS) $(O_FILES) -o $(NAME) $(LIBFT_L) $(MLX_LIB) $(GPU_L)
	make clean

%.o:%.c includes/fractol.h srcs/size.h
	$(CC) $(CC_FLAGS) -c -o $@ $< $(LIBFT_I) $(MLX_I) \
	$(GPU_MACRO) $(PRECISION) $(SPECIAL)

clean: cleanp clean_libft

cleanp:
	rm -rf $(O_FILES)

clean_libft:
	make -C libft clean

fclean: fclean_libft fcleanp

fcleanp: cleanp
	rm -rf $(NAME)

fclean_libft:
	make -C libft fclean

re: fclean all

rep: fcleanp all

wre: wmode re

wrep: wmode rep

wmode:
	$(eval CC_FLAGS = -Wall -Wextra -Werror)

re_libft:
	make -C libft re

GPU: set_gpu_flags all

gpu: GPU

CPU: all

cpu: CPU

set_gpu_flags:
	@echo "\x1b[1;33mGPU flags are being set."\
	" Make clean if linkage error happen\x1b[0m"
	$(eval GPU_L = -framework OpenCL)
	$(eval GPU_MACRO = -DGPU)

repgpu: fcleanp GPU

repcpu: fcleanp CPU

noprecision:
	$(eval PRECISION =)

special:
	$(eval SPECIAL = -DUNDEFINED)
