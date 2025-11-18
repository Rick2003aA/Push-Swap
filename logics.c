/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:29:31 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/18 11:45:13 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	f;
	int	s;
	int	t;

	f = (*stack)->value;
	s = (*stack)->next->value;
	t = (*stack)->next->next->value;
	if (f > s && s < t && t < f)
	{
		rotate(stack);
		printf("ra\n");
	}
	else if (f > s && s > t && t < f)
	{
		swap_node(stack);
		printf("sa\n");
		rev_rotate(stack);
		printf("rra\n");
	}
	else if (f < s && s > t && t < f)
	{
		rev_rotate(stack);
		printf("rra\n");
	}
	else if (f > s && s < t && t > f)
	{
		swap_node(stack);
		printf("sa\n");
	}
	else if (f < s && s > t && t > f)
	{
		swap_node(stack);
		printf("sa\n");
		rotate(stack);
		printf("ra\n");
	}
}

int	find_min(t_node *stack)
{
	t_node	*tmp;
	int		min;

	tmp = stack;
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

void	bring_min_to_top(t_node **stack, int min)
{
	while ((*stack)->value != min)
	{
		rotate(stack);
		printf("ra\n");
	}
}

void	sort_five(t_node **a, t_node **b)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	while (count_nodes(*a) > 3)
	{
		min = find_min(*a);
		bring_min_to_top(a, min);
		push(a, b);
		printf("pb\n");
		i++;
	}
	sort_three(a);
	j = 0;
	while (j++ < i)
	{
		push(b, a);
		printf("pa\n");
	}
}

// void	bubble_sort(int *arr, int size)
// {
// 	int	i;
// 	int	flag;
// 	int	tmp;

// 	flag = 1;
// 	while (flag)
// 	{
// 		flag = 0;
// 		i = 0;
// 		while (i < size - 1)
// 		{
// 			if (arr[i] > arr[i + 1])
// 			{
// 				tmp = arr[i];
// 				arr[i] = arr[i + 1];
// 				arr[i + 1] = tmp;
// 				flag = 1;
// 			}
// 			i++;
// 		}
// 	}
// }

// void	assign_ranks2(t_node *tmp, int size, int *arr)
// {
// 	int	i;

// 	while (tmp)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (tmp->value == arr[i])
// 			{
// 				tmp->rank = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		tmp = tmp->next;
// 	}
// 	free (arr);
// }

// void	assign_ranks(t_node *stack)
// {
// 	int		size;
// 	int		*arr;
// 	int		i;
// 	t_node	*tmp;

// 	size = count_nodes(stack);
// 	tmp = stack;
// 	arr = malloc(sizeof(int) * size);
// 	if (!arr)
// 	{
// 		free(arr);
// 		return ;
// 	}
// 	i = 0;
// 	while (tmp)
// 	{
// 		arr[i] = tmp->value;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	bubble_sort(arr, size);
// 	tmp = stack;
// 	assign_ranks2(tmp, size, arr);
// }

// int	get_max_bits(t_node *stack)
// {
// 	int	bits;
// 	int	max;

// 	max = 0;
// 	while (stack)
// 	{
// 		if (stack->rank > max)
// 			max = stack->rank;
// 		stack = stack->next;
// 	}
// 	bits = 0;
// 	while (max > 0)
// 	{
// 		max = max / 2;
// 		bits++;
// 	}
// 	return (bits);
// }

// int	make_binary(int n)
// {
// 	int	result;

// 	result = 1;
// 	while (n > 0)
// 	{
// 		result = result * 2;
// 		n--;
// 	}
// 	return (result);
// }

// void	radix_sort2(t_node **a, t_node **b, int i, int size)
// {
// 	int	j;
// 	int	bit;

// 	j = 0;
// 	while (j < size && *a)
// 	{
// 		bit = (((*a)->rank / make_binary(i)) % 2);
// 		if (bit == 0)
// 		{
// 			push(a, b);
// 			printf("pb\n");
// 		}
// 		else
// 		{
// 			rotate(a);
// 			printf("ra\n");
// 		}
// 		j++;
// 	}
// }

// void	radix_sort(t_node **a, t_node **b)
// {
// 	int	max_bits;
// 	int	size;
// 	int	i;

// 	assign_ranks(*a);
// 	max_bits = get_max_bits(*a);
// 	size = count_nodes(*a);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		radix_sort2(a, b, i, size);
// 		while (*b)
// 		{
// 			push(b, a);
// 			printf("pa\n");
// 		}
// 		i++;
// 	}
// }
