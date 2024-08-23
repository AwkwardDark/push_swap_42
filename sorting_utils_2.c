/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:13:00 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 11:42:27 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	match;

	ft_set_median(a);
	ft_set_median(b);
	while (a)
	{
		current_b = b;
		match = LONG_MIN;
		while (current_b)
		{
			if ((a->value > current_b->value) && (match < current_b->value))
			{
				match = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LONG_MIN)
			a->target = ft_find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	ft_set_target_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long	match;

	ft_set_median(a);
	ft_set_median(b);
	while (b)
	{
		current_a = a;
		match = LONG_MAX;
		while (current_a)
		{
			if ((b->value < current_a->value) && (match > current_a->value))
			{
				match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (match == LONG_MAX)
			b->target = ft_find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

static int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static int	ft_same_half(t_node *a, t_node *b, int len_a, int len_b)
{
	if ((a->index < ft_median(len_a)) && (b->index < ft_median(len_b)))
		return (1);
	else if ((a->index >= ft_median(len_a)) && (b->index >= ft_median(len_b)))
		return (1);
	return (0);
}

void	ft_set_cost(t_node *a, t_node *b)
{
	int	l_a;
	int	l_b;

	l_a = ft_lstlen(a);
	l_b = ft_lstlen(b);
	while (a)
	{
		a->cost = a->index;
		a->target->cost = a->target->index;
		if (!a->target->above_median)
			a->target->cost = l_b - a->target->index;
		if (!a->above_median)
			a->cost = l_a - a->index;
		a->cost += a->target->cost;
		if (ft_same_half(a, a->target, l_a, l_b) && a->above_median)
			a->cost = ft_max(a->index, a->target->index);
		if (ft_same_half(a, a->target, l_a, l_b) && !a->above_median)
			a->cost = ft_max(l_a - a->index, l_b - a->target->index);
		a = a->next;
	}
}
