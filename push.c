/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:25:06 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/11 16:34:00 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_node **src, t_node **dest)
{
	t_node	*push;

	if (!*src)
		return ;
	push = *src;
	if ((*src)->next)
	{
		*src = (*src)->next;
		(*src)->next->prev = NULL;
	}
	if (!*dest)
	{
		*dest = push;
		(*dest)->next = NULL;
	}
	else
	{
		push->next = *dest;
		push->next->prev = push;
		*dest = push;
	}	
}

void	pa(t_node **b, t_node **a)
{
	ft_push(b, a);
}

void	pb(t_node **b, t_node **a)
{
	ft_push(a, b);
}
