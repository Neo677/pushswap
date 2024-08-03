/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RR.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:33:03 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:33:05 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rott(t_stackys **stack)
{
	int		len;
	t_stackys	*lst_node;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	lst_node = discover_last_lone(*stack);
	lst_node->next_one = *stack;
	*stack = (*stack)->next_one;
	(*stack)->previous_node = NULL;
	lst_node->next_one->previous_node = lst_node;
	lst_node->next_one->next_one = NULL;
}

void	ra(t_stackys **a, bool check)
{
	rott(a);
	if (!check)
		write(1, "ra\n", 3);
}

void	rb(t_stackys **b, bool check)
{
	rott(b);
	if (!check)
		write(1, "rb\n", 3);
}

void	rr(t_stackys **a, t_stackys **b, bool check)
{
	rott(a);
	rott(b);
	if (!check)
		write(1, "rr\n", 3);
}
