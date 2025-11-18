/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:30:13 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/18 12:33:34 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pf_ra(t_node **stack)
{
	rotate(stack);
	printf("ra\n");
}

void	pf_rra(t_node **stack)
{
	rev_rotate(stack);
	printf("rra\n");
}

void	pf_sa(t_node **stack)
{
	swap_node(stack);
	printf("sa\n");
}
