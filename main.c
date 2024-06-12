/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:39:43 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/12 22:24:30 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ft_check_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_parse_stack(ac, av, &a);
	ft_push_swap(&a, &b);
	while(a)
	{
		printf("Value: %d || Target Value: %d || Cost Value: %d\n", a->value, a->target->value, a->cost);
		a = a->next;
	}
	ft_free_lst(&a);
	return (0);
}
