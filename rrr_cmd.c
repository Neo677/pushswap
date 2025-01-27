/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RRR.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:53 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:52:33 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stackys **stack)
{
	t_stackys	*tail;
	int				len;

	len = count_stack_nodes(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	tail = get_tail_node(*stack);
	if (tail->prev != NULL)
		tail->prev->next = NULL;
	tail->next = *stack;
	tail->prev = NULL;
	(*stack)->prev = tail;
	*stack = tail;
}

void	rra(t_stackys **a, bool checker)
{
	reverse_rotate_stack(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stackys **b, bool checker)
{
	reverse_rotate_stack(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stackys **a, t_stackys **b, bool checker)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
