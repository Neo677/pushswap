/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:01:24 by thobenel          #+#    #+#             */
/*   Updated: 2024/07/26 19:06:12 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stackys	*discover_last_lone(stackys *top)
{
	if (top == NULL)
		return (NULL);
	while (top->next_one)
		top = top->next_one;
	return (top);
}

void	look_lst_node(stackys **stack, int nb)
{
	stackys	*node;
	stackys	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(stackys));
	if (!node)
		return ;
	node->next_one = NULL;
	node->value = nb;
	if (*stack == NULL)
	{
		*stack = node;
		node->previous_node = NULL;
	}
	else
	{
		last = discover_last_lone(*stack);
		last->next_one = node;
		node->previous_node = last;
	}
}

stackys	*find_smallest(stackys *stack)
{
	long	small;
	stackys	*small_node;

	if (stack == NULL)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->value < small)
		{
			small = stack->value;
			small_node = stack;
		}
	}
	return (small_node);
}

stackys	*return_less(stackys *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheaper)
			return (stack);
		stack = stack->next_one;
	}
	return (NULL);
}

int	stack_len(stackys *stack)
{
	int compteur;

	if (stack == NULL)
		return (0);
	compteur = 0;
	while (stack)
	{
		compteur++;
		stack = stack->next_one;
	}
	return (compteur);
}