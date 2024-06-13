/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_push_nodes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:39:37 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/13 19:31:31 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	ft_set_index(*a);
	ft_set_index(*b);
}

static void	ft_rev_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	ft_set_index(*a);
	ft_set_index(*b);
}

static void	ft_finish_rotation(t_node **stack, t_node *cheapest, char s)
{
	while (*stack != cheapest)
	{
		if (s == 'a')
		{
			if (cheapest->above_median)
				ra(stack, 0);
			else
				rra(stack, 0);
		}
		else if (s == 'b')
		{
			if (cheapest->above_median)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}

void	ft_push_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	cheapest = ft_cheapest(*a);
	if (cheapest->above_median && cheapest->target->above_median)
		ft_rotate_both(a, b, cheapest);
	if (!cheapest->above_median && !cheapest->target->above_median)
		ft_rev_rotate_both(a, b, cheapest);
	ft_finish_rotation(a, cheapest, 'a');
	ft_finish_rotation(b, cheapest->target, 'b');
	pb(a, b);
}

void	ft_push_b_to_a(t_node **a, t_node **b)
{
	ft_finish_rotation(a, (*b)->target, 'a');
	pa(a, b);
}
