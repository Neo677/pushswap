/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:31:51 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:46:33 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stackys	*a;
	t_stackys	*b;
	char		**decoupe;

	a = NULL;
	b = NULL;
	if (ac == 2 && (ac != 1 || (ac != 2 && !av[1][0])))
	{
		decoupe = ft_split(av[1], ' ');
		initialize_stack(&a, decoupe, true);
		free_background(decoupe);
	}
	else if (ac > 2 && (ac != 1 || (ac != 2 && !av[1][0])))
		initialize_stack(&a, av + 1, false);
	if (!stack_sorted(a) && (ac != 1 || (ac != 2 && !av[1][0])))
	{
		if (count_stack_nodes(a) == 2)
			sa(&a, false);
		else if (count_stack_nodes(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (1);
}




// int	main(int ac, char **av)
// {
// 	t_stackys	*a;
// 	t_stackys	*b;
// 	char		**decoupe;

// 	a = NULL;
// 	b = NULL;
// 	if (ac == 1 || (ac == 2 && !av[1][0]))
// 		return (1);
// 	else if (ac == 2)
// 	{
// 		decoupe = ft_split(av[1], ' ');
// 		initialize_stack(&a, decoupe, true);
// 		free_background(decoupe);
// 	}
// 	else
// 		initialize_stack(&a, av + 1, false);
// 	if (!stack_sorted(a))
// 	{
// 		if (count_stack_nodes(a) == 2)
// 			sa(&a, false);
// 		else if (count_stack_nodes(a) == 3)
// 			tiny_sort(&a);
// 		else
// 			push_swap(&a, &b);
// 	}
// 	free_stack(&a);
// }
