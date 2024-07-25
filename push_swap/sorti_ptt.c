/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorti_ptt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:41:52 by thobenel          #+#    #+#             */
/*   Updated: 2024/07/25 15:41:54 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool sortie_stack(stackys *stack)
{
	if (stack == NULL)
		return (1);
	while(stack->next_one)
	{
		if (stack->value > stack->next_one->value)
			return (false);
		stack = stack->next_one;
	}
	return (true);
}

static stackys *highest_in_the_stack(stackys *stack)
{
	int 	hig;
	stackys	*bigest_node;

	if (stack == NULL)
		return (NULL);
	hig = INT_MIN;
	while(stack)
	{
		if (stack->value > hig)
		{
			hig = stack->value;
			bigest_node = stack;
		}
		stack = stack->next_one;
	}
	return (hig);
}

void	tiny(stackys **stack_A)
{
	stackys *hig_node;

	hig_node = highest_in_the_stack(*stack_A);
	if (*stack_A == hig_node)
		ra(stack_A, false);
	else if ((*stack_A)->next_one == hig_node)
		rra(stack_A, false);
	if ((*stack_A)->value > (*stack_A)->next_one->value)
		sa(stack_A, false);
}

void	five(stackys	**a, stackys		**b)
{
	while(stack_len(*a) > 3)
	{
		init_stack(*a, *b);
		
	}
}