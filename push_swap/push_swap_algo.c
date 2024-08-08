/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:34 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:47:11 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void	rotate_stacks_both(t_stackys **a, t_stackys **b,
		t_stackys *min_cost_node)
{
	while (*a != min_cost_node->target_node && *b != min_cost_node)
		rr(a, b, false);
	update_current_position(*a);
	update_current_position(*b);
}

static void	reverse_rotate_stacks_both(t_stackys **a, t_stackys **b,
		t_stackys *min_cost_node)
{
	while (*a != min_cost_node->target_node && *b != min_cost_node)
		rrr(a, b, false);
	update_current_position(*a);
	update_current_position(*b);
}

void	finish_rotation(t_stackys **stack, t_stackys *top_node,
		char stack_id)
{
	while (*stack != top_node)
	{
		if (stack_id == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_id == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	execute_moves(t_stackys **a, t_stackys **b)
{
	t_stackys	*min_cost_node;

	min_cost_node = locate_cheapest(*b);
	if (min_cost_node->above_median && min_cost_node->target_node->above_median)
		rotate_stacks_both(a, b, min_cost_node);
	else if (!(min_cost_node->above_median)
		&& !(min_cost_node->target_node->above_median))
		reverse_rotate_stacks_both(a, b, min_cost_node);
	finish_rotation(b, min_cost_node, 'b');
	finish_rotation(a, min_cost_node->target_node, 'a');
	pa(a, b, false);
}

void	push_swap(t_stackys **a, t_stackys **b)
{
	t_stackys	*smallest;
	int				stack_size_a;

	stack_size_a = count_stack_nodes(*a);
	if (stack_size_a == 5)
		handle_five(a, b);
	else
	{
		while (stack_size_a-- > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		initialize_nodes(*a, *b);
		execute_moves(a, b);
	}
	update_current_position(*a);
	smallest = find_minimum(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
