/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:58:04 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/10 19:11:45 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_node **lst)
{
	t_node	*head;
	t_node	*last;
	
	head = *lst;
	last = ft_lstlast(*lst);
	head->next->prev = NULL;
	head->next = NULL;
	head->prev = last;
	last->next = head;
}