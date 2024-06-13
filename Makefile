# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:37:18 by pajimene          #+#    #+#              #
#    Updated: 2024/06/13 19:30:50 by pajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

SRC =	main.c \
		parsing.c \
		rotate_cmd.c \
		rev_rotate_cmd.c \
		push_cmd.c \
		swap_cmd.c \
		push_swap_algorithm.c \
		rotate_push_nodes.c

UTILS_SRC = ft_split.c \
			linked_list_utils_1.c \
			linked_list_utils_2.c \
			sorting_utils.c \
			check_error.c \
			free_memory.c

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