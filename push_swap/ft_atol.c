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

//			ft_atol
static long	ft_atoi_to_long(const char *str)
{
	long	num;
	int		isneg;
	int		i;

	num = 0;
	isneg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * isneg);
}

void	initialize_stack(t_stackys **a, char **argv, bool flag_argc_2)
{
	long	value;
	int		i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		value = ft_atoi_to_long(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)value))
			error_free(a, argv, flag_argc_2);
		add_node_to_stack(a, (int)value);
		i++;
	}
	if (flag_argc_2)
		free_background(argv);
}
