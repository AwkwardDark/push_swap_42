/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:13:00 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/12 22:42:24 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_index(t_node *a)
{
	int	i;
	
	i = 0;
	while (a)
	{
		a->index = i;
		a = a->next;
		i++;
	}
}

void	ft_set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	int		match;

	while (a)
	{
		current_b = b;
		match = INT_MIN;
		while (current_b)
		{
			if ((a->value > current_b->value) && (match < current_b->value))
			{
				match = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == INT_MIN)
			a->target = ft_find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	ft_set_cost(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;
	int	median_a;
	int	median_b;

	len_a = ft_lstlen(a);
	len_b = ft_lstlen(b);
	median_a = len_a / 2 + 1;
	median_b = len_b / 2 + 1;
	while (a)
	{
		if (a->target->index >= median_b)
			a->target->cost = len_b - a->target->index;
		a->cost = a->index;
		if (a->index < median_a)
			a->cost += a->target->cost;
		else if (a->index >= median_b)
		{
			a->cost = len_a - a->index;
			a->cost += a->target->index;
		}
		a = a->next;
	}
}
