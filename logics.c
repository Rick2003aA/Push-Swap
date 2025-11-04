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
		rotate(stack);
	else if (f > s && s > t && t < f)
	{
		swap_node(stack);
		rev_rotate(stack);
	}
	else if (f < s && s > t && t < f)
		rev_rotate(stack);
	else if (f > s && s < t && t > f)
		swap_node(stack);
	else if (f < s && s > t && t > f)
	{
		swap_node(stack);
		rotate(stack);
	}
}

int	find_min(t_node *stack)
{
	t_node	*tmp;
	int	min;

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
		rotate(stack);
}

int	count_nodes(t_node *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
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
		i++;
	}
	sort_three(a);
	j = 0;
	while (j++ < i)
		push(b, a);
}