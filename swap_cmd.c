/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:25:16 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 12:58:17 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_node **lst)
{
	if (!lst || !*lst || ft_lstlen(*lst) == 1)
		return ;
	*lst = (*lst)->next;
	(*lst)->prev->prev = *lst;
	(*lst)->prev->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = (*lst)->prev;
	(*lst)->next = (*lst)->prev;
	(*lst)->prev = NULL;
}

void	sa(t_node **a, int flag)
{
	ft_swap(a);
	if (!flag)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int flag)
{
	ft_swap(b);
	if (!flag)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b, int flag)
{
	sa(a, 1);
	sb(b, 1);
	if (!flag)
		write(1, "ss\n", 3);
}
