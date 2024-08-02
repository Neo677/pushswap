// 				header

#include "push_swap.h"

static void	rtt_a_b(stackys **stack_a, stackys **stack_b, stackys *m_cheap)
{
	while (*stack_a != m_cheap->target && *stack_b != m_cheap)
		rr(stack_a, stack_b, false);
	suivi_de_pos(*stack_a);
	suivi_de_pos(*stack_b);
}

static void	rev_rot_a_b(stackys **stack_a, stackys **stack_b, stackys *m_cheap)
{
	while (*stack_a != m_cheap->target && *stack_b != m_cheap)
		rrr(stack_a, stack_b, false);
	suivi_de_pos(*stack_a);
	suivi_de_pos(*stack_b);
}

void	end_R(stackys **stack, stackys *top, char name)
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

static void	mv_node(stackys **stack_a, stackys **stack_b)
{
	stackys	*chp;

	chp = return_less(*stack_b);
	if (chp->median && chp->target->median)
		rtt_a_b(stack_a, stack_b, chp);
	else if (!(chp->median) && !(chp->target->median))
		rev_rot_a_b(stack_a, stack_b, chp);
	end_R(stack_b, chp, 'b');
	end_R(stack_a, chp, 'a');
	pa(stack_a, stack_b, false);
}

void	push_swap(stackys **stack_a, stackys **stack_b)
{
	stackys *sml;
	int i;

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