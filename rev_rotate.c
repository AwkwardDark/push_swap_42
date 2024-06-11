/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:56 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/11 16:33:50 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_node **lst)
{
	t_node	*last;

	if (!lst || !*lst || ft_lstlen(*lst) == 1)
		return ;
	last = ft_lstlast(*lst);
	last->prev->next = NULL;
	last->next = *lst;
	last->prev = NULL;
	*lst = last;
	last->next->prev = last;
}

void	rra(t_node **a, int flag)
{
	ft_rev_rotate(a);
	if (!flag)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int flag)
{
	ft_rev_rotate(b);
	if (!flag)
		write(1, "rra\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}
