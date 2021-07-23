# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 22:29:25 by jnakahod          #+#    #+#              #
#    Updated: 2021/07/23 03:33:50 by jnakahod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

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

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)

$(NAME): $(MLX_DIR) $(OBJCS) $(LIBFT_LIB)
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
		$(MAKE) -C $(LIBFT_DIR) bonus
		$(CC) -g $(CFLAGS) $(SRCS) -L$(MLX_DIR) $(LIBS) $(LIBFT_LIB) $(INCLUDE) -o $(NAME)

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666 ./$(NAME) mandelbrot dynamic

.PHONY: all clean fclean re test
