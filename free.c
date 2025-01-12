/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:30:59 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:46:12 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	free_stack(t_stackys **stack)
{
	t_stackys	*tmp;
	t_stackys	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// free for ft_split
void	free_background(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		av[i] = NULL;
		i++;
	}
	free(av);
	av = NULL;
}

// alternate version
// void free_background(char **av)
// {
//     int i = 0;

//     if (av == NULL || *av == NULL)
//         return ;

//     // Libérer chaque segment
//     while (av[i])
//     {
//         printf("Freeing: %p (content: %s)\n", (void *)av[i], av[i]);
//         free(av[i]);  // Libérer chaque segment
//         av[i] = NULL;  // Réinitialiser après libération
//         i++;
//     }

//     // Libérer le tableau principal seulement s'il a été alloué
//     printf("Freeing av: %p\n", (void *)av);
//    // free(av);  // Libérer le tableau principal
//     av = NULL;  // Réinitialiser après libération
//     printf("Memory freed successfully\n");  // Débogage
// }

void	error_free(t_stackys **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_background(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stackys *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
		{
			return (1);
		}
		a = a->next;
	}
	return (0);
}
// printf("repeat found = %d\n", nbr);
