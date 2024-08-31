/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:27:07 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/31 23:59:14 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

static void	determine_target_node(t_stackys *a, t_stackys *b)
{
	t_stackys	*current_a;
	t_stackys	*best_target;
	long			lowest_value_above;

	while (b)
	{
		lowest_value_above = LONG_MAX;
		current_a = a;
		while (current_a != NULL)
		{
			if (current_a->value > b->value
				&& current_a->value < lowest_value_above)
			{
				lowest_value_above = current_a->value;
				best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (lowest_value_above == LONG_MAX)
			b->target_node = find_minimum(a);
		else
			b->target_node = best_target;
		b = b->next;
	}
}

void	set_cheapest(t_stackys *b)
{
	long			lowest_cost;
	t_stackys	*cheapest_node;

	lowest_cost = LONG_MAX;
	cheapest_node = NULL;
	if (b == NULL)
		return ;
	while (b != NULL)
	{
		if (b->push_price < lowest_cost)
		{
			lowest_cost = b->push_price;
			cheapest_node = b;
		}
		b = b->next;
	}
	if (cheapest_node != NULL)
		cheapest_node->cheapest = true;
}

void	calculate_cost(t_stackys *a, t_stackys *b)
{
	int	len_a;
	int	len_b;

	len_a = count_stack_nodes(a);
	len_b = count_stack_nodes(b);
	while (b != NULL)
	{
		b->push_price = b->current_position;
		if (!b->above_median)
			b->push_price = len_b - b->current_position;
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += len_a - b->target_node->current_position;
		b = b->next;
	}
}

void	update_current_position(t_stackys *stack)
{
	int	i;
	int	mid_point;

	i = 0;
	if (stack == NULL)
		return ;
	mid_point = count_stack_nodes(stack) / 2;
	while (stack != NULL)
	{
		stack->current_position = i;
		stack->above_median = (i <= mid_point);
		stack = stack->next;
		i++;
	}
}

void	initialize_nodes(t_stackys *a, t_stackys *b)
{
	update_current_position(a);
	update_current_position(b);
	determine_target_node(a, b);
	calculate_cost(a, b);
	set_cheapest(b);
}
 