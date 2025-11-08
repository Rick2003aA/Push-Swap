#include "push_swap.h"

void	parse_node(t_node **a, t_node **b)
{
	int		i;

	i = count_nodes(*a);
	if (i == 3)
		sort_three(a);
	else if (3 < i && i < 6)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_node	*a = NULL;
	t_node	*b = NULL;
	int		i;

	(void)ac;
	i = 1;
	while (av[i])
	{
		push_back(&a, av[i]);
		i++;
	}
	// printf("Before: ");
	// print_stack(a);

	parse_node(&a, &b);

	// printf("After:  ");
	// print_stack(a);
}
