/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:29:13 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/12 18:24:30 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **av)
{
	int	i;

	if (!av || !*av)
		return ;
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	ft_free_lst(t_node **a)
{
	t_node	*temp;

	while (*a)
	{
		temp = (*a)->next;
		free(*a);
		*a = temp;
	}
}
