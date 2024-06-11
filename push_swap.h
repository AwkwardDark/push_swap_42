/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:40:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/11 16:35:11 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node {
	int				value;
	int				position;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

//Error Check & Free memory
int		ft_check_error(int ac, char **av);
int		ft_check_syntax(char *str);
int		ft_check_repetition(char **av, int nbr);
void	ft_free(char **av);

//String Utils
char	**ft_split(char const *s, char c);
long	ft_atol(char *str);

//Linked List Utils
t_node	*ft_lstnew(int nbr);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lst_sort(t_node **lst);
void	ft_lstclear(t_node **lst);
int		ft_lstlen(t_node *lst);
t_node	*ft_biggest(t_node **lst);

//Stack Parsing
void	ft_parse_stack(int ac, char **av, t_node **a);

//Instructions
void	ft_rotate(t_node **lst);
void	ra(t_node **a, int flag);
void	rb(t_node **b, int flag);
void	rr(t_node **a, t_node **b);
void	ft_rev_rotate(t_node **lst);
void	rra(t_node **a, int flag);
void	rrb(t_node **b, int flag);
void	rrr(t_node **a, t_node **b);
void	ft_swap(t_node **lst);
void	sa(t_node **a, int flag);
void	sb(t_node **b, int flag);
void	ss(t_node **a, t_node **b);
void	ft_push(t_node **src, t_node **dest);

//Sorting Algorithm
void	ft_push_swap(t_node **a, t_node **b);
void	ft_sort_3(t_node **a);

#endif