/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:12 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:46:41 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

//			ft_atoi
static long	ft_atoi_long(const char *str)
{
	long	nb;
	int		neg;
	int		i;

	nb = 0;
	neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	printf("Converting %s to long: %ld\n", str, nb * neg);
	return (nb * neg);
}

void	initialize_stack(t_stackys **a, char **av, bool flg_nb_ac)
{
	long	value;
	int		i;

	i = 0;
	while (av[i] != NULL)
	{
		printf("process arg: %s\n", av[i]);
		if (error_syntax(av[i]))
		{
			error_free(a, av, flg_nb_ac);
		}
			
		value = ft_atoi_long(av[i]);
		printf("converted value: %ld\n", value);
		/*if (value > INT_MAX || value < INT_MIN)
		{
			error_free(a, av, flg_nb_ac);
		}*/
			
		if (error_repetition(*a, (int)value))
		{
			printf("Repetition detected for value: %d\n", (int)value);
			error_free(a, av, flg_nb_ac);
		}
			
		add_node_to_stack(a, (int)value);
		i++;
	}
	if (flg_nb_ac)
		free_background(av);
}
