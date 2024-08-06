/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:51 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/05 20:31:09 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stackys	*a;
	t_stackys	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (printf("only 1 argument"), 1);
	else if (2 == argc)
	{
		printf("only 2 argument\n");
		argv = ft_split(argv[1], ' ');
		printf("argv = %d\n", argc);
	}
	init_stack(&a, argv + 1, 2 == argc);
	if (!sortie_stack(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny(&a);
		else
			push_swap(&a, &b);
	}
	free_pile(&a);
}