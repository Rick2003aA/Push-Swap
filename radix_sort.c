/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:43:12 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/28 15:48:24 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort2(t_node **a, t_node **b, int i, int size)
{
	int	j;
	int	bit;

	j = 0;
	while (j < size)
	{
		bit = (((*a)->rank / make_binary(i)) % 2);
		if (bit == 0)
		{
			push(a, b);
			ft_printf("pb\n");
		}
		else
		{
			rotate(a);
			ft_printf("ra\n");
		}
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
			ft_printf("pa\n");
		}
		i++;
	}
}
