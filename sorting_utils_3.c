/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:39:44 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 11:41:40 by pajimene         ###   ########.fr       */
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

int	ft_median(int len)
{
	return (len / 2 + 1);
}

void	ft_set_median(t_node *a)
{
	int	median;

	median = ft_median(ft_lstlen(a));
	while (a)
	{
		if (a->index < median)
			a->above_median = 1;
		else
			a->above_median = 0;
		a = a->next;
	}
}

t_node	*ft_cheapest(t_node *a)
{
	t_node	*cheapest;
	int		cost;

	cost = INT_MAX;
	while (a)
	{
		if (a->cost < cost)
		{
			cost = a->cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}
