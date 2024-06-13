/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:49:52 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/13 19:19:25 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_node **a)
{
	t_node	*max;
	t_node	*head;

	head = *a;
	max = ft_find_max(*a);
	if (head == max)
		ra(a, 0);
	else if (head->next == max)
		rra(a, 0);
	if (!ft_is_sort(a))
		sa(a, 0);
}

static void	ft_refresh_stack_a(t_node *a, t_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_a(a, b);
	ft_set_cost(a, b);
}

static void	ft_refresh_stack_b(t_node *a, t_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_b(a, b);
}

static void	ft_sort_big(t_node **a, t_node **b)
{
	int	len_a;

	len_a = ft_lstlen(*a);
	if (len_a-- > 3 && !ft_is_sort(a))
		pb(a, b);
	if (len_a-- > 3 && !ft_is_sort(a))
		pb(a, b);
	while (len_a-- > 3 && !ft_is_sort(a))
	{
		ft_refresh_stack_a(*a, *b);
		ft_push_a_to_b(a, b);
	}
	ft_refresh_stack_a(*a, *b);
	ft_sort_three(a);
	while (*b)
	{
		ft_refresh_stack_b(*a, *b);
		ft_push_b_to_a(a, b);
	}
	ft_set_index(*a);
	ft_last_sort(a);
}

void	ft_push_swap(t_node **a, t_node **b)
{
	(void)b;
	if (!*a || ft_is_sort(a))
		return ;
	else if (ft_lstlen(*a) == 2)
		sa(a, 0);
	else if (ft_lstlen(*a) == 3)
		ft_sort_three(a);
	else
		ft_sort_big(a, b);
	return ;
}
