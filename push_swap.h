/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:40:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/12 22:17:48 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node {
	int				value;
	int				index;
	int				cost;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

//Error Check & Free memory & Parsing
int		ft_check_error(int ac, char **av);
int		ft_check_syntax(char *str);
int		ft_check_repetition(char **av, int nbr);
void	ft_free_split(char **av);
void	ft_free_lst(t_node **a);
void	ft_parse_stack(int ac, char **av, t_node **a);

//String Utils
char	**ft_split(char const *s, char c);
long	ft_atol(char *str);

//Linked List Utils
t_node	*ft_lstnew(int nbr);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_is_sort(t_node **lst);
//void	ft_lstclear(t_node **lst);
int		ft_lstlen(t_node *lst);
t_node	*ft_find_max(t_node *lst);
t_node	*ft_find_min(t_node *lst);

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
void	pa(t_node **b, t_node **a);
void	pb(t_node **a, t_node **b);

//Sorting Utils
void	ft_set_index(t_node *a);
void	ft_set_target_a(t_node *a, t_node *b);
void	ft_refresh_stack_a(t_node *a, t_node *b);
void	ft_set_cost(t_node *a, t_node *b);

//Sorting Algorithm
void	ft_push_swap(t_node **a, t_node **b);
void	ft_sort_three(t_node **a);
//void	ft_sort_four(t_node **a, t_node **b);
void	ft_sorting(t_node **a, t_node **b);

#endif