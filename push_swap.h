/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:40:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/10 19:10:33 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

//Error Check
int		ft_check_error(int ac, char **av);
int		ft_check_syntax(char *str);
int		ft_check_repetition(char **av, int nbr);

//String Utils
char	**ft_split(char const *s, char c);
long	ft_atol(char *str);
void	ft_free(char **av);

//Linked List Utils
t_node	*ft_lstnew(int nbr);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lst_sort(t_node **lst);
void	ft_lstclear(t_node **lst);

//Stack Parsing
void	ft_parse_stack(int ac, char **av, t_node **a);

//Operations
void	ft_rotate(t_node **lst);

#endif