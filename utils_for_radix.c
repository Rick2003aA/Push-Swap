/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:44:47 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/12/15 18:57:11 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	flag;
	int	tmp;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = 1;
			}
			i++;
		}
	}
}

void	assign_ranks2(t_node *tmp, int size, int *arr)
{
	int	i;

	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == arr[i])
			{
				tmp->rank = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free (arr);
}

void	assign_ranks(t_node *stack)
{
	int		size;
	int		*arr;
	int		i;
	t_node	*tmp;

	size = count_nodes(stack);
	tmp = stack;
	arr = malloc(sizeof(int) * size);
	//修正
	if (!arr)
	{
		free(arr);
		return ;
	}
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(arr, size);
	tmp = stack;
	assign_ranks2(tmp, size, arr);
}

int	get_max_bits(t_node *stack)
{
	int	bits;
	int	max;

	max = 0;
	while (stack)
	{
		if (stack->rank > max)
			max = stack->rank;
		stack = stack->next;
	}
	bits = 0;
	while (max > 0)
	{
		max = max / 2;
		bits++;
	}
	return (bits);
}

int	make_binary(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result = result * 2;
		n--;
	}
	return (result);
}
