# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 22:29:25 by jnakahod          #+#    #+#              #
#    Updated: 2021/07/12 16:12:51 by jnakahod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# UNAME_S := $(shell uname -s)
# ifeq ($(UNAME_S), Linux)
# 	PLATFORM := LINUX
# endif
# ifeq ($(UNAME_S), Darwin)
# 	PLATFORM := MACOS
# endif

# ifeq ($(PLATFORM), LINUX)
# 	INCLUDE = -I ./includes -Iminilibx-linux -Ilibft
# 	MLX_LIB := libmlx_Linux.a
# 	MLX_DIR := ./minilibx-linux
# 	LIBS = -lmlx_Linux -lXext -lX11 -lm
# endif

# ifeq ($(PLATFORM), MACOS)
# 	INCLUDE = -I ./includes -Iminilibx_mms_20200219
# 	MLX_LIB := libmlx.dylib
# 	MLX_DIR := ./minilibx_mms_20200219
# 	#MINILIB_DIR := minilibx_opengl_20191021
# 	LIBS := libmlx.dylib -framework OpenGL -framework Appkit -lm
# 	#LIBS := -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework Appkit
# endif

INCLUDE = -I ./includes -Iminilibx-linux -Ilibft
MLX_LIB := libmlx_Linux.a
MLX_DIR := ./minilibx-linux
LIBS = -lmlx_Linux -lXext -lX11 -lm

SRCS =	srcs/main.c \
		srcs/init.c \
		srcs/exit.c \
		srcs/event.c \
		srcs/set_mandelbrot.c \
		srcs/set_burningship.c \
		srcs/set_julia.c \
		srcs/load_info_from_parameters.c \
		srcs/utils.c

OBJCS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJCS) $(LIBFT_LIB)
		$(MAKE) -C $(MLX_DIR)
		cp $(MLX_DIR)/$(MLX_LIB) .
		$(CC) $(CFLAGS) $(OBJCS) -L$(MLX_DIR) $(LIBS) $(LIBFT_LIB) $(INCLUDE) -o $(NAME)

$(LIBFT_LIB):
		$(MAKE) -C $(LIBFT_DIR) bonus

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $@

-include $(DEPS)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		$(RM) $(OBJCS) $(DEPS)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJCS) $(DEPS)
		$(RM) $(NAME) $(MLX_LIB)

re: fclean all

test:
		$(CC) -g $(CFLAGS) $(SRCS) -L$(MLX_DIR) $(LIBS) $(LIBFT_LIB) $(INCLUDE) -o $(NAME)

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666 ./$(NAME) julia plain

.PHONY: all clean fclean re test
