// header

#include "push_swap.h"

static void	rev_rot(stackys **stack)
{
	stackys	*lst;
	int		i;

	i = stack_len(*stack);
	if (*stack == NULL || stack == NULL || i == 1)
		return ;
	lst = find_smallest(*stack);
	lst->previous_node->next_one = NULL;
	lst->next_one = *stack;
	lst->previous_node = NULL;
	*stack = lst;
	lst->next_one->previous_node = lst;
}

void	rra(stackys **satck_a, bool check)
{
	rev_rot(satck_a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(stackys **stack_b, bool check)
{
	rev_rot(stack_b);
	if (!check)
		write(1, "rrb\n", 4);
}
void	rrr(stackys **stack_a, stackys **stack_b, bool check)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	if (!check)
		write(1, "rrr\n", 4);
}