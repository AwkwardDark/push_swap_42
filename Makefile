# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:37:18 by pajimene          #+#    #+#              #
#    Updated: 2024/06/10 19:11:37 by pajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

SRC =	main.c \
		check_error.c \
		parse_stack.c \
		operations.c

UTILS_SRC = ft_split.c \
			linked_list_utils.c \
			string_utils.c

OBJ = $(SRC:.c=.o)
UTILS_OBJ = $(UTILS_SRC:.c=.o)

HEADER = push_swap.h

NAME = push_swap

all: $(NAME) clean

$(NAME): $(OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(UTILS_OBJ)

clean:
	rm -f $(OBJ) $(UTILS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re