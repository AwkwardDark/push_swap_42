/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:50:03 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/10 18:52:04 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_stack(int ac, char **av, t_node **a)
{
	int		i;
	long	nbr;
	
	i = 1;
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		ft_lstadd_back(a, ft_lstnew(nbr));
		i++;
	}
	if (ac == 2)
		ft_free(av);
	return ;
}