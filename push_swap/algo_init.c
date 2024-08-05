/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:27:07 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:27:10 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "push_swap.h"

void	suivi_de_pos(t_stackys *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= center)
			stack->median = true;
		else
			stack->median = false;
		stack = stack->next_one;
		i++;
	}
}

static void	def_target(t_stackys *stack_a, t_stackys *stack_b)
{
	t_stackys	*current_stack_a;
	t_stackys	*targette;
	long int	match;

	while (stack_b)
	{
		match = LONG_MAX;
		current_stack_a = stack_a;
		while (current_stack_a)
		{
			if (current_stack_a->value > stack_b->value
				&& current_stack_a->value < match)
			{
				match = current_stack_a->value;
				targette = current_stack_a;
			}
			current_stack_a = current_stack_a->next_one;
		}
		if (match == LONG_MAX)
			stack_b->target = find_smallest(stack_a);
		else
			stack_b->target = targette;
		stack_b = stack_b->next_one;
	}
}

void	price(t_stackys *stack_a, t_stackys *stack_b)
{
	int	i;
	int	j;

	i = stack_len(stack_a);
	j = stack_len(stack_b);
	while (stack_b)
	{
		stack_b->push_pr = stack_b->position;
		if (!(stack_b->median))
			stack_b->push_pr = j - (stack_b->position);
		if (stack_b->target->median)
			stack_b->push_pr += stack_b->target->position;
		else
			stack_b->push_pr += i - (stack_b->target->position);
		stack_b = stack_b->next_one;
	}
}

void	cheap(t_stackys *stack_b)
{
	long int	i;
	t_stackys	*match;

	if (stack_b == NULL)
		return ;
	i = LONG_MAX;
	while (stack_b)
	{
		if (stack_b->push_pr < i)
		{
			i = stack_b->push_pr;
			match = stack_b;
		}
		stack_b = stack_b->next_one;
	}
	match->cheaper = true;
}

void	init_vl(t_stackys *stack_b, t_stackys *stack_a)
{
	suivi_de_pos(stack_a);
	suivi_de_pos(stack_b);
	def_target(stack_a, stack_b);
	price(stack_a, stack_b);
	cheap(stack_b);
}
