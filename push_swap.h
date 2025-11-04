#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct e_node
{
	int				value;//value of elements
	struct e_node	*next;//pointer to the next node
}	t_node;

//methods
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);
void	swap_node(t_node **stack);
void	push(t_node **src, t_node **dest);
//logics
void	sort_three(t_node **stack);
//utils
t_node	*new_node(int value);
void	push_back(t_node **stack, int value);
void	print_stack(t_node *stack);

#endif