/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:28:54 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/12/15 18:48:50 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	error_exit(t_node *stack)
{
	write(2, "Error\n", 6);
	free_list(stack);
	exit(1);
}

void	push_back(t_node **stack, char *value, char **split)
{
	t_node		*new;
	t_node		*tmp;
	long long	n;
	int			err;

	n = ft_atoi(value, &err);
	if (err)
	{
		free_split(split);
		error_exit(*stack);
	}
	new = new_node(n);
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

// void	print_stack(t_node *stack)
// {
// 	while (stack)
// 	{
// 		ft_printf("%d, ", stack->value);
// 		stack = stack->next;
// 	}
// 	ft_printf("\n");
// }

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
