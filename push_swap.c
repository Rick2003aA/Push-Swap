/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:54:15 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/16 13:13:59 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_node(t_node **a, t_node **b)
{
	int		i;

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
	int	n;
	int	error;

	i = 1;
	error = 0;
	while (av[i])
	{
		n = ft_atoi(av[i], &error);
		if (error)
			return (1);
		j = i + 1;
		while (av[j])
		{
			if (atoi(av[i]) == atoi(av[j]))
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
	(void)ac;
	if (error_check(av))
	{
		printf("Error");
		return (0);
	}
	i = 1;
	while (av[i])
	{
		push_back(&a, av[i]);
		i++;
	}
	parse_node(&a, &b);
}
