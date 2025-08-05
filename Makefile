# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 13:15:45 by vahdekiv          #+#    #+#              #
#    Updated: 2025/08/05 14:42:06 by vahdekiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libft/
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
SRCS = main.c maps.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

clean:
		@rm -f *.o
		@make clean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME) $(LIBFT)

re: fclean all

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES) 

.PHONY: all clean fclean re
