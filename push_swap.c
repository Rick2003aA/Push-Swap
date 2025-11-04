#include "push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a = NULL;

	push_back(&a, 5);
	push_back(&a, 8);
	push_back(&a, 2);

	printf("Before: ");
	print_stack(a);

	sort_three(&a);

	printf("After:  ");
	print_stack(a);
}