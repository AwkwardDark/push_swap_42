/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:40:11 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 14:00:50 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node {
	int				value;
	int				index;
	int				cost;
	int				above_median;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

//Parsing, Handle Error, and Free Memory
int		ft_check_error(int ac, char **av);
void	ft_free_split(char **av);
void	ft_free_lst(t_node **a);
void	ft_parse_stack(int ac, char **av, t_node **a);
char	**ft_split(char const *s, char c);
long	ft_atol(char *str);

//Linked List Utils
t_node	*ft_lstnew(int nbr);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);

//Instructions
void	ra(t_node **a, int flag);
void	rb(t_node **b, int flag);
void	rr(t_node **a, t_node **b, int flag);
void	rra(t_node **a, int flag);
void	rrb(t_node **b, int flag);
void	rrr(t_node **a, t_node **b, int flag);
void	sa(t_node **a, int flag);
void	sb(t_node **b, int flag);
void	ss(t_node **a, t_node **b, int flag);
void	pa(t_node **b, t_node **a, int flag);
void	pb(t_node **a, t_node **b, int flag);

//Sorting Utils
void	ft_set_index(t_node *a);
int		ft_median(int len);
void	ft_set_median(t_node *a);
void	ft_set_target_a(t_node *a, t_node *b);
void	ft_set_target_b(t_node *a, t_node *b);
void	ft_set_cost(t_node *a, t_node *b);
t_node	*ft_cheapest(t_node *a);
int		ft_is_sort(t_node **lst);
int		ft_lstlen(t_node *lst);
t_node	*ft_find_max(t_node *lst);
t_node	*ft_find_min(t_node *lst);

//Sorting Algorithm
void	ft_push_swap(t_node **a, t_node **b);
void	ft_push_a_to_b(t_node **a, t_node **b);
void	ft_push_b_to_a(t_node **a, t_node **b);
void	ft_last_sort(t_node **a);

//Bonus Checker
void	ft_checker(t_node **a, t_node **b, char *line);
void	ft_verify_free(t_node **a, t_node **b);

//GNL Utils
char	*get_next_line(int fd, int error);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *str, char c);
void	*ft_calloc(int size, int number);

#endif