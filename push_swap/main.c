// header

#include "push_swap.h"

int 	main(int ac, char **av)
{
	stackys	*stack_a;
	stackys *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&stack_a, av + 1, ac == 2);
	if (!sortie_stack(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			tiny(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_pile(&stack_a);
}