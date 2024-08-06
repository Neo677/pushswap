/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pt-1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:33:41 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/05 22:20:38 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stackys	*discover_last_lone(t_stackys *top)
{
	if (top == NULL)
		return (NULL);
	while (top->next_one)
		top = top->next_one;
	return (top);
}

void	look_lst_node(t_stackys **stack, int nb)
{
	t_stackys	*node;
	t_stackys	*last;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stackys));
	if (node == NULL)
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

t_stackys	*find_smallest(t_stackys *stack)
{
	long	small;
	t_stackys	*small_node;

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
		stack = stack->next_one;
	}
	return (small_node);
}

t_stackys	*return_less(t_stackys *stack)
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

int	stack_len(t_stackys *stack)
{
	int compteur;

	if (stack == NULL)
		return (0);
	compteur = 0;
	while (stack)
	{
		++compteur;
		stack = stack->next_one;
	}
	return (compteur);
}
