/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:55:52 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/12 21:21:17 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstlen(t_node *lst)
{
	int		i;
	t_node	*current;

	i = 0;
	current = lst;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

t_node	*ft_find_max(t_node *lst)
{
	t_node	*max;
	t_node	*current;

	current = lst;
	max = current;
	while (current->next)
	{
		if (max->value < current->next->value)
			max = current->next;
		current = current->next;
	}
	return (max);
}

t_node	*ft_find_min(t_node *lst)
{
	t_node	*min;
	t_node	*current;

	current = lst;
	min = current;
	while (current->next)
	{
		if (min->value > current->next->value)
			min = current->next;
		current = current->next;
	}
	return (min);
}
