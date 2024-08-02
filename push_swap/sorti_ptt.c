/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorti_ptt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:41:52 by thobenel          #+#    #+#             */
/*   Updated: 2024/07/26 19:06:03 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sortie_stack(stackys *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next_one)
	{
		if (stack->value > stack->next_one->value)
			return (false);
		stack = stack->next_one;
	}
	return (true);
}

static stackys	*highest_in_the_stack(stackys *stack)
{
	int		hig;
	stackys	*bigest_node;

	if (stack == NULL)
		return (NULL);
	hig = INT_MIN;
	while (stack)
	{
		if (stack->value > hig)
		{
			hig = stack->value;
			bigest_node = stack;
		}
		stack = stack->next_one;
	}
	return (bigest_node);
}

void	tiny(stackys **stack_a)
{
	stackys	*hig_node;

	hig_node = highest_in_the_stack(*stack_a);
	if (*stack_a == hig_node)
		ra(stack_a, false);
	else if ((*stack_a)->next_one == hig_node)
		rra(stack_a, false);
	if ((*stack_a)->value > (*stack_a)->next_one->value)
		sa(stack_a, false);
}

void	five(stackys **stack_a, stackys **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		init_vl(*stack_a, *stack_b);
		end_R(stack_a, find_smallest(*stack_a), 'a');
		pb(stack_b, stack_a, false);
	}
}