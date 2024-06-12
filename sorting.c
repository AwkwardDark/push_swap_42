/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:49:52 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/12 22:22:10 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_sorting(a, b);
	return ;
}

void	ft_sort_three(t_node **a)
{
	t_node	*max;

	max = ft_find_max(*a);
	if (*a == max)
		ra(a, 0);
	else if ((*a)->next == max)
		rra(a, 0);
	if (!ft_is_sort(a))
		sa(a, 0);
	return ;
}

// void	ft_sort_four(t_node **a, t_node **b)
// {
// 	pb(a, b);
// 	ft_sort_three(a);
// 	while ((*a)->value < (*b)->value)
// 		ra(a, 0);
// 	pa(a, b);
// 	while (!ft_lst_sort(a))
// 		rra(a, 0);
// 	return ;
// }

void	ft_sorting(t_node **a, t_node **b)
{
	int	len_a;

	len_a = ft_lstlen(*a);
	if (len_a-- > 3 && !ft_is_sort(a))
		pb(a, b);
	if (len_a-- > 3 && !ft_is_sort(a))
		pb(a, b);
	pb(a, b);
	pb(a, b);
	pb(a, b);
	//while (len_a-- > 3 && !ft_is_sort(a))
	//{
	ft_refresh_stack_a(*a, *b);
		//ft_push_a_to_b(a, b);
	//}
	//ft_sort_three(a);
	// while (*b)
	// {
	// 	ft_refresh_stack_b(*a, *b);
	// 	ft_push_b_to_a(a, b);
	// }
	// ft_set_index(*a);
	//ft_last_sort(a);
}

void	ft_refresh_stack_a(t_node *a, t_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_a(a, b);
	ft_set_cost(a, b);
	//ft_set_cheapest(a);
}