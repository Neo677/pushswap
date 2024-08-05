/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:34 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:32:36 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rtt_a_b(t_stackys **stack_a, t_stackys **stack_b,
		t_stackys *m_cheap)
{
	while (*stack_a != m_cheap->target && *stack_b != m_cheap)
		rr(stack_a, stack_b, false);
	suivi_de_pos(*stack_a);
	suivi_de_pos(*stack_b);
}

static void	rev_rot_a_b(t_stackys **stack_a, t_stackys **stack_b,
		t_stackys *m_cheap)
{
	while (*stack_a != m_cheap->target && *stack_b != m_cheap)
		rrr(stack_a, stack_b, false);
	suivi_de_pos(*stack_a);
	suivi_de_pos(*stack_b);
}

void	end_r(t_stackys **stack, t_stackys *top, char name)
{
	while (*stack != top)
	{
		if (name == 'a')
		{
			if (top->median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b')
		{
			if (top->median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	mv_node(t_stackys **stack_a, t_stackys **stack_b)
{
	t_stackys	*chp;

	chp = return_less(*stack_b);
	if (chp->median && chp->target->median)
		rtt_a_b(stack_a, stack_b, chp);
	else if (!(chp->median) && !(chp->target->median))
		rev_rot_a_b(stack_a, stack_b, chp);
	end_r(stack_b, chp, 'b');
	end_r(stack_a, chp, 'a');
	pa(stack_a, stack_b, false);
}

void	push_swap(t_stackys **stack_a, t_stackys **stack_b)
{
	t_stackys	*sml;
	int			i;

	i = stack_len(*stack_a);
	if (i == 5)
		five(stack_a, stack_b);
	else
	{
		while (i-- > 3)
			pb(stack_b, stack_a, false);
	}
	tiny(stack_a);
	while (*stack_b)
	{
		init_vl(*stack_a, *stack_b);
		mv_node(stack_a, stack_b);
	}
	suivi_de_pos(*stack_a);
	sml = find_smallest(*stack_a);
	if (sml->median)
		while (*stack_a != sml)
			ra(stack_a, false);
	else
		while (*stack_a != sml)
			rra(stack_a, false);
}
