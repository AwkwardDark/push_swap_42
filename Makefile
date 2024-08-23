# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 17:37:18 by pajimene          #+#    #+#              #
#    Updated: 2024/06/14 13:30:38 by pajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	=	main.c \
			push_swap_algorithm.c \
			rotate_push_nodes.c

UTILS_SRC = ft_split.c \
			parsing.c \
			linked_list_utils.c \
			sorting_utils_1.c \
			sorting_utils_2.c \
			sorting_utils_3.c \
			rotate_cmd.c \
			rev_rotate_cmd.c \
			push_cmd.c \
			swap_cmd.c \
			check_error.c \
			free_memory.c

SRC_B 	= 	main_bonus.c \
			checker.c \
			get_next_line.c \
			get_next_line_utils.c

OBJ 	= 	$(SRC:.c=.o)

UTILS_OBJ = $(UTILS_SRC:.c=.o)

OBJ_B	=	$(SRC_B:.c=.o)

NAME 	=	push_swap

NAME_B 	= 	checker

CC 		= 	cc

CFLAGS 	= 	-Wall -Werror -Wextra -g3

all: 		$(NAME)

bonus: 		$(NAME_B)

$(NAME): 	$(OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(UTILS_OBJ)

$(NAME_B):  $(OBJ_B) $(UTILS_OBJ)
	$(CC) $(CFLAGS) -c $(SRC_B)
	$(CC) $(CFLAGS) -o $(NAME_B) $(UTILS_OBJ) $(OBJ_B)

clean:
	rm -f $(OBJ) $(UTILS_OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all bonus

.PHONY: all clean fclean re bonus