# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 22:29:25 by jnakahod          #+#    #+#              #
#    Updated: 2021/06/12 22:30:43 by jnakahod         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

LIBS = -lXext -lX11
MLX_DIR = ./minilibx-linux

SRCS = srcs/main.c \

OBJCS = $(SRCS:%.c=%.o)

INCLUDE = ./includes

RM = rm -f

all: $(NAME)

$(NAME): $(OBJCS)
		$(MAKE) -C $(LIBFT_DIR) bonus
		$(MAKE) -C $(MLX_DIR)
		cp $(MLX_DIR)/libmlx_Linux.a .
		$(CC) $(CFLAGS) $(OBJCS) -L. -Lminilibx-linux -lmlx_Linux $(LIBS) -lm $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME)
clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		$(MAKE) -C $(MLX_DIR) clean
		$(RM) $(OBJCS)

fclean: clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		$(RM) $(OBJCS)
		$(RM) $(NAME) ./libmlx_Linux.a

re: fclean all

test:
		$(CC) -g $(SRCS) -L. -Lminilibx-linux -lmlx_Linux $(LIBS) -lm $(LIBFT_LIB) -I $(INCLUDE) -o $(NAME)

.PHONY: all clean fclean re test
