/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorti_ptt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:33:12 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:33:13 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sortie_stack(t_stackys *stack)
{
	if (stack == NULL)
		return (free(stack), 1);
	while (stack->next_one)
	{
		if (stack->value > stack->next_one->value)
			return (false);
		stack = stack->next_one;
	}
	return (true);
}

static t_stackys	*highest_in_the_stack(t_stackys *stack)
{
	int		hig;
	t_stackys	*bigest_node;

	if (stack == NULL)
		return (free(stack), NULL);
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

void	tiny(t_stackys **stack_a)
{
	t_stackys	*hig_node;

	hig_node = highest_in_the_stack(*stack_a);
	if (*stack_a == hig_node)
		ra(stack_a, false);
	else if ((*stack_a)->next_one == hig_node)
		rra(stack_a, false);
	if ((*stack_a)->value > (*stack_a)->next_one->value)
		sa(stack_a, false);
}

void	five(t_stackys **stack_a, t_stackys **stack_b)
{
	while (stack_len(*stack_a) > 3)
	{
		init_vl(*stack_a, *stack_b);
		end_r(stack_a, find_smallest(*stack_a), 'a');
		pb(stack_b, stack_a, false);
	}
}
