/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:26:48 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/13 19:35:35 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int nbr)
{
	t_node		*lstnew;

	lstnew = malloc(sizeof(t_node));
	if (!lstnew)
		return (NULL);
	lstnew->value = nbr;
	lstnew->next = NULL;
	lstnew->prev = NULL;
	return (lstnew);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*current;

	current = lst;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}
