/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:51 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:31:54 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stackys	*stack_a;
	t_stackys	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_stack(&stack_a, av + 1, ac == 2);
	printf("checker_1\n");
	if (sortie_stack(stack_a))
	{
		printf("checker_2\n");
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			tiny(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
		printf("checker_3\n");
	}
	printf("checker_4\n");
	free_pile(&stack_a);
}