/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:00:27 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/11 16:32:08 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(int ac, char **av)
{
	int		i;
	long	nbr;

	i = 1;
	if (ac == 2)
	{
		if (!av[1][0])
			return (1);
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i])
	{
		if (ft_check_syntax(av[i]))
			return (1);
		nbr = atol(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		if (ft_check_repetition(av + i + 1, (int)nbr))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_syntax(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_repetition(char **av, int nbr)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) == nbr)
			return (1);
		i++;
	}
	return (0);
}