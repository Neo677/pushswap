/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:33:41 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/07 01:01:22 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack_node	*get_tail_node(t_stack_node *start)
{
	if (start == NULL)
		return (NULL);
	while (start->next != NULL)
		start = start->next;
	return (start);
}

void	add_node_to_stack(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (stack == NULL)
		return;
	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (node == NULL)
		return;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_tail_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*find_minimum(t_stack_node *stack)
{
	long			min_value;
	t_stack_node	*min_node;

	if (stack == NULL)
		return (NULL);
	min_value = LONG_MAX;
	while (stack != NULL)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack_node	*locate_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	count_stack_nodes(t_stack_node *stack)
{
	int	total;

	total = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		total++;
		stack = stack->next;
	}
	return (total);
}