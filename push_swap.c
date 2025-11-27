/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:54:15 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/27 14:50:49 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_node(t_node **a, t_node **b)
{
	int	i;

	i = count_nodes(*a);
	if (i == 3)
		sort_three(a);
	else if (3 < i && i < 6)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	error_check(char **av)
{
	int	i;
	int	j;
	int	error;

	i = 1;
	error = 0;
	while (av[i])
	{
		ft_atoi(av[i], &error);
		if (error)
			return (1);
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i], &error) == ft_atoi(av[j], &error))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac == 2)
	{
		av = ft_split(av[i], ' ');
		i = 0;
	}
	if (ac < 2 || error_check(av))
	{
		ft_printf("Error\n");
		return (0);
	}
	while (av[i])
	{
		push_back(&a, av[i]);
		i++;
	}
	parse_node(&a, &b);
	return (0);
}
