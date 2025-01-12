/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:33:41 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:48:54 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stackys	*get_tail_node(t_stackys *start)
{
	if (start == NULL)
		return (NULL);
	while (start->next != NULL)
		start = start->next;
	return (start);
}

void	add_node_to_stack(t_stackys **stack, int nbr)
{
	t_stackys	*node;
	t_stackys	*last_node;

	if (stack == NULL)
		return ;
	node = (t_stackys *)malloc(sizeof(t_stackys));
	if (node == NULL)
		return ;
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

t_stackys	*find_minimum(t_stackys *stack)
{
	long			min_value;
	t_stackys	*min_node;

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

t_stackys	*locate_cheapest(t_stackys *stack)
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

int	count_stack_nodes(t_stackys *stack)
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
