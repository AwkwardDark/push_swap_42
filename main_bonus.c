/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:33:56 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 14:00:42 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ft_check_error(ac, av))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_parse_stack(ac, av, &a);
	line = get_next_line(0, 0);
	while (line)
	{
		ft_checker(&a, &b, line);
		free(line);
		line = get_next_line(0, 0);
	}
	free(line);
	ft_verify_free(&a, &b);
	return (0);
}
