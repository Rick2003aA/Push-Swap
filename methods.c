/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:29:11 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/18 12:29:32 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rev_rotate(t_node **stack)
{
	t_node	*mid;
	t_node	*last;

	if (!stack && !*stack && !(*stack)->next)
		return ;
	mid = NULL;
	last = *stack;
	while (last->next)
	{
		mid = last;
		last = last->next;
	}
	mid->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	swap_node(t_node **stack)
{
	t_node	*first;
	t_node	*mid;

	first = *stack;
	mid = first->next;
	*stack = mid;
	first->next = mid->next;
	mid->next = first;
}

void	push(t_node **src, t_node **dest)
{
	t_node	*s_first;
	t_node	*d_first;

	if (!src || !*src)
		return ;
	s_first = *src;
	d_first = *dest;
	*dest = s_first;
	*src = s_first->next;
	s_first->next = d_first;
}
