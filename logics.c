/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:29:31 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/27 14:50:49 by rtsubuku         ###   ########.fr       */
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
		pf_ra(stack);
	else if (f > s && s > t && t < f)
	{
		pf_sa(stack);
		pf_rra(stack);
	}
	else if (f < s && s > t && t < f)
		pf_rra(stack);
	else if (f > s && s < t && t > f)
		pf_sa(stack);
	else if (f < s && s > t && t > f)
	{
		pf_sa(stack);
		pf_ra(stack);
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
		ft_printf("ra\n");
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
		ft_printf("pb\n");
		i++;
	}
	sort_three(a);
	j = 0;
	while (j++ < i)
	{
		push(b, a);
		ft_printf("pa\n");
	}
}
