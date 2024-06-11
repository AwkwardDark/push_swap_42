/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:55:52 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:40 by pajimene         ###   ########.fr       */
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

t_node	*ft_biggest(t_node **lst)
{
	t_node	*big;
	t_node	*current;

	big = malloc(sizeof(t_node));
	if (!big)
		return (NULL);
	current = *lst;
	big = current;
	while (current->next)
	{
		if (big->value < current->next->value)
			big = current->next;
		current = current->next;
	}
	return (big);
}
