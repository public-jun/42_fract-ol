# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 22:29:25 by jnakahod          #+#    #+#              #
#    Updated: 2021/06/22 09:14:33 by jnakahod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

LIBS = -lmlx -lXext -lX11 -lm
MLX_DIR = ./minilibx-linux

SRCS =	srcs/main.c \
		# srcs/load_info_from_parameters.c

OBJCS = $(SRCS:%.c=%.o)

INCLUDE = -I ./includes

RM = rm -f

all: $(NAME)

$(NAME): $(OBJCS) $(LIBFT_LIB)
		$(MAKE) -C $(MLX_DIR)
		cp $(MLX_DIR)/libmlx.a .
		$(CC) $(CFLAGS) $(OBJCS) -Lminilibx-linux $(LIBS) $(LIBFT_LIB) $(INCLUDE) -o $(NAME)

$(LIBFT_LIB):	
		$(MAKE) -C $(LIBFT_DIR) bonus

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		$(RM) $(OBJCS)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJCS)
		$(RM) $(NAME) ./libmlx.a

re: fclean all

test:
		$(CC) -g $(CFLAGS) $(SRCS) -Lminilibx-linux $(LIBS) $(LIBFT_LIB) $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re test
