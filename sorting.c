/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:49:52 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:57 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_node **a, t_node **b)
{
	(void)b;
	if (!*a || ft_lst_sort(a))
		return ;
	if (ft_lstlen(*a) == 3)
	{	
		ft_sort_3(a);
	}
	return ;
}

void	ft_sort_3(t_node **a)
{
	t_node	*biggest;
	t_node	*head;

	biggest = ft_biggest(a);
	head = *a;
	if (head == biggest)
		ra(a, 0);
	else if (head->next == biggest)
	{
		rra(a, 0);
	}
	if (!ft_lst_sort(a))
		sa(a, 0);
	free(biggest);
	return ;
}
