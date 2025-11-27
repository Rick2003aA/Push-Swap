/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:43:12 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/27 14:24:13 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_for_zero(t_node *a, int i)
{
	t_node	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->rank / make_binary(i) % 2 == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	radix_sort2(t_node **a, t_node **b, int i, int size)
{
	int	j;
	int	bit;

	j = 0;
	while (j < size && *a)
	{
		bit = (((*a)->rank / make_binary(i)) % 2);
		if (bit == 0)
		{
			push(a, b);
			printf("pb\n");
		}
		else if (search_for_zero(*a, i))
		{
			rotate(a);
			printf("ra\n");
		}
		else
			break ;
		j++;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	max_bits;
	int	size;
	int	i;

	assign_ranks(*a);
	max_bits = get_max_bits(*a);
	size = count_nodes(*a);
	i = 0;
	while (i < max_bits)
	{
		radix_sort2(a, b, i, size);
		while (*b)
		{
			push(b, a);
			printf("pa\n");
		}
		i++;
	}
}
