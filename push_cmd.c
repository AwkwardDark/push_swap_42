/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:25:06 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 12:56:39 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_node **src, t_node **dest)
{
	t_node	*push;

	if (!*src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push->prev = NULL;
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

void	pa(t_node **a, t_node **b, int flag)
{
	ft_push(b, a);
	if (!flag)
		write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, int flag)
{
	ft_push(a, b);
	if (!flag)
		write(1, "pb\n", 3);
}
