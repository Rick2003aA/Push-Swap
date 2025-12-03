/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:54:15 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/12/03 11:04:42 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_node(t_node **a, t_node **b)
{
	int	i;

	i = count_nodes(*a);
	if (i == 2 && (*a)->value > (*a)->next->value)
	{
		pf_ra(a);
		return ;
	}
	else if (i == 3)
		sort_three(a);
	else if (3 < i && i < 6)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	error_check(t_node *a)
{
	t_node	*list1;
	t_node	*list2;

	list1 = a;
	while (list1)
	{
		if (list1->value > INT_MAX || list1->value < INT_MIN)
			return (1);
		list2 = list1->next;
		while (list2)
		{
			if (list1->value == list2->value)
				return (1);
			list2 = list2->next;
		}
		list1 = list1->next;
	}
	return (0);
}

void	arrange_str(int ac, char **av, t_node **a)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split || !split[0])
		{
			free_split(split);
			return ;
		}
		j = 0;
		while (split[j])
		{
			push_back(a, split[j]);
			j++;
		}
		free_split(split);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	arrange_str(ac, av, &a);
	if (error_check(a))
	{
		free_list(a);
		write(2, "Error\n", 6);
		return (0);
	}
	parse_node(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
