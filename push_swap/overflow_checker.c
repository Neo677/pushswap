/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:12 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:32:15 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	num;
	int		neg;
	int		i;

	i = 0;
	num = 0;
	neg = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' 
									|| str[i] == '\r' || str[i] == '\v' 
									|| str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

void	init_stack(t_stackys **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_fix(argv[i]))
			free_mystake(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_mystake(a, argv, flag_argc_2);
		if (repeat_error(*a, (int)nbr))
			free_mystake(a, argv, flag_argc_2);
		look_lst_node(a, (int)nbr);
		++i;
	}
	if (flag_argc_2)
		free_thbackgrd(argv);
}
