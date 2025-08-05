# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 14:18:55 by vahdekiv          #+#    #+#              #
#    Updated: 2025/05/27 13:46:01 by vahdekiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_isdigit.c ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c \
       ft_strnstr.c ft_bzero.c ft_isprint.c ft_memcpy.c ft_putstr_fd.c \
       ft_strlcat.c ft_strrchr.c ft_calloc.c ft_itoa.c ft_memmove.c \
       ft_split.c ft_strlcpy.c ft_strtrim.c ft_isalnum.c ft_memset.c \
       ft_strchr.c ft_strlen.c ft_substr.c ft_isalpha.c ft_putchar_fd.c \
       ft_strdup.c ft_strmapi.c ft_tolower.c ft_isascii.c ft_memchr.c \
       ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c \
	   printf_hex.c ft_printf.c printf_utils.c  get_next_line.c \
	   get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean: 
	@rm -f $(OBJS)
	@echo "removing objects"

fclean: clean
	@rm -f $(NAME)
	@echo "removing executable file"

re: fclean all

.PHONY: all clean fclean re
