// header

#include "push_swap.h"

static void	push(stackys **dst, stackys **src)
{
	stackys	*nd_push;

	if (*src == NULL)
		return ;
	nd_push = *src;
	*src = (*src)->next_one;
	if (*src)
		(*src)->previous_node = NULL;
	nd_push->previous_node = NULL;
	if (*dst == NULL)
	{
		*dst = nd_push;
		nd_push->next_one = NULL;
	}
	else
	{
		nd_push->next_one = *dst;
		nd_push->next_one->previous_node = nd_push;
		*dst = nd_push;
	}
}

void	pa(stackys **stack_a, stackys **stack_b, bool checker)
{
	push(stack_a, stack_b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(stackys **stack_a, stackys **stack_b, bool checker)
{
	push(stack_b, stack_a);
	if (!checker)
		write(1, "pb\n", 3);
}