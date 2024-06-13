/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:39 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/13 19:26:31 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_node **lst)
{
	t_node	*last;

	if (!lst || !*lst || ft_lstlen(*lst) == 1)
		return ;
	last = ft_lstlast(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_node **a, int flag)
{
	ft_rotate(a);
	if (!flag)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int flag)
{
	ft_rotate(b);
	if (!flag)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}
