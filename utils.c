#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	push_back(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = new_node(value);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d", stack->value);
		stack = stack->next;
	}
	printf("\n");
}