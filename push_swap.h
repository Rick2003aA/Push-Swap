/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:29:26 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/27 16:12:07 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

typedef struct e_node
{
	int				value;//value of elements
	int				rank;//for putting ranks to each elements
	struct e_node	*next;//pointer to the next node
}	t_node;

typedef struct s_pf
{
	const char	*fmt;
	int			i;
	size_t		written;
	va_list		ap;
	char		spec;
}	t_pf;

//methods
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);
void	swap_node(t_node **stack);
void	push(t_node **src, t_node **dest);

//logics
void	sort_three(t_node **stack);
void	sort_five(t_node **a, t_node **b);
int		find_min(t_node *stack);
void	bring_min_to_top(t_node **stack, int min);

// //print_methods
void	pf_ra(t_node **stack);
void	pf_rra(t_node **stack);
void	pf_sa(t_node **stack);

//radix_sort
void	radix_sort(t_node **a, t_node **b);
void	radix_sort2(t_node **a, t_node **b, int i, int size);

//utils for radix
void	bubble_sort(int *arr, int size);
void	assign_ranks(t_node *stack);
void	assign_ranks2(t_node *tmp, int size, int *arr);
int		get_max_bits(t_node *stack);
int		make_binary(int n);

//utils
t_node	*new_node(int value);
void	push_back(t_node **stack, char *value);
// void	print_stack(t_node *stack);
int		count_nodes(t_node *stack);

//others from libft
int		ft_atoi(const char *nptr, int *error);
char	**ft_split(char const *s, char c);

//for ft_printf
int		ft_printf(const char *fmt, ...);
void	pf_putc(t_pf *st, char c);
void	pf_puts(t_pf *st, char *s);
void	pf_putu(t_pf *st, unsigned long long nb);
void	pf_put_hex(t_pf *st, unsigned long long u, char *list);
void	pf_parse(t_pf *st);
void	pf_dispatch(t_pf *st);
void	pf_print_c(t_pf *st);
void	pf_print_s(t_pf *st);
void	pf_print_di(t_pf *st);
void	pf_print_u(t_pf *st);
void	pf_print_x(t_pf *st);
void	pf_print_p(t_pf *st);

#endif