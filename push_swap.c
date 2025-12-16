/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:54:15 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/12/15 18:51:08 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *tmp)
{
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	parse_node(t_node **a, t_node **b)
{
	int		i;

	if (is_sorted(*a))
		return ;
	i = count_nodes(*a);
	if (i == 2)
	{
		if ((*a)->value > (*a)->next->value)
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
			push_back(a, split[j], split);
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
	if (ac == 1)
		return (0);
	arrange_str(ac, av, &a);
	if (error_check(a))
		error_exit(a);
	parse_node(&a, &b);
	free_list(a);
	free_list(b);
	return (0);
}
