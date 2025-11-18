/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:26 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/18 12:34:51 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct e_node
{
	int				value;//value of elements
	int				rank;//for putting ranks to each elements
	struct e_node	*next;//pointer to the next node
}	t_node;

//methods
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);
void	swap_node(t_node **stack);
void	push(t_node **src, t_node **dest);

//logics
void	sort_three(t_node **stack);
void	sort_five(t_node **a, t_node **b);

//print_methods
void	pf_ra(t_node **stack);
void	pf_rra(t_node **stack);
void	pf_sa(t_node **stack);

//radix_sort
void	radix_sort(t_node **a, t_node **b);

//utils for radix
void	bubble_sort(int *arr, int size);
void	assign_ranks2(t_node *tmp, int size, int *arr);
void	assign_ranks(t_node *stack);
int		get_max_bits(t_node *stack);
int		make_binary(int n);

//utils
t_node	*new_node(int value);
void	push_back(t_node **stack, char *value);
void	print_stack(t_node *stack);
int		count_nodes(t_node *stack);

//others from libft
int		ft_atoi(const char *nptr, int *error);
char	**ft_split(char const *s, char c);

#endif