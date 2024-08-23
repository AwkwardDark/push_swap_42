/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:45:26 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/14 14:01:05 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error_free(t_node **a, t_node **b, char *cmd)
{
	free(cmd);
	ft_free_lst(a);
	ft_free_lst(b);
	get_next_line(0, 1);
	write(2, "Error\n", 6);
	exit(0);
}

static int	ft_strncmp(char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_checker(t_node **a, t_node **b, char *cmd)
{
	if (!ft_strncmp(cmd, "pa\n", 3))
		pa(a, b, 1);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		pb(a, b, 1);
	else if (!ft_strncmp(cmd, "sa\n", 3))
		sa(a, 1);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		sb(b, 1);
	else if (!ft_strncmp(cmd, "ss\n", 3))
		ss(a, b, 1);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		ra(a, 1);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rb(b, 1);
	else if (!ft_strncmp(cmd, "rr\n", 3))
		rr(a, b, 1);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		rra(a, 1);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		rrb(b, 1);
	else if (!ft_strncmp(cmd, "rrr\n", 4))
		rrr(a, b, 1);
	else
		ft_error_free(a, b, cmd);
}

void	ft_verify_free(t_node **a, t_node **b)
{
	if (ft_is_sort(a) && ft_lstlen(*b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_lst(a);
	ft_free_lst(b);
}
