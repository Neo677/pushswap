/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RR.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:33:03 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:52:02 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stackys **stack)
{
	t_stackys *last_node;
	int				len;

	len = count_stack_nodes(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	last_node = get_tail_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stackys **a, bool checker)
{
	rotate_stack(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stackys **b, bool checker)
{
	rotate_stack(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stackys **a, t_stackys **b, bool checker)
{
	rotate_stack(a);
	rotate_stack(b);
	if (!checker)
		write(1, "rr\n", 3);
}
