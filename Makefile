# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 13:15:45 by vahdekiv          #+#    #+#              #
#    Updated: 2025/08/14 13:41:49 by vahdekiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(MLX_DIR)/include -I$(LIBFT_DIR)
SRCS = main.c maps.c path.c so_long_utils.c cleanup.c error_handling.c \
launch_game.c events.c

O_DIR = objects

OBJS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = MLX42

MLX_LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

all: $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(MLX_DIR):
		git clone https://github.com/codam-coding-college/MLX42 $(MLX_DIR)
		cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(NAME): $(MLX_DIR) $(LIBFT) $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) -o $(NAME)

$(O_DIR):
		mkdir -p $@

$(O_DIR)/%.o: %.c so_long.h | $(O_DIR)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
		@rm -rf $(O_DIR) $(MLX_DIR)
		@make fclean -C $(LIBFT_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean re
