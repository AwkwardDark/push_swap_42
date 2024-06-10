/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:39:43 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/10 19:12:28 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node *a;
	
	a = NULL;
	if (ac == 1)
		return (1);
	if (ft_check_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_parse_stack(ac, av, &a);
	// if (ft_lst_sort(&a))
	// {
	// 	ft_lstclear(&a);
	// 	return(0);
	// }
	while (a)
	{
		printf("Value -> %d\n", a->value);
		a = a->next;
	}
	ft_rotate(&a);
	printf("\nAfter rotating\n");
	while (a)
	{
		printf("Value -> %d\n", a->value);
		a = a->next;
	}
	return (0);
}
