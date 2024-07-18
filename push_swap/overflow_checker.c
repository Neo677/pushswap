/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:30:17 by thobenel          #+#    #+#             */
/*   Updated: 2024/07/18 17:30:21 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *str)
{
	long num;
	int  neg;
	int i;

	i = 0;
	num = 0;
	neg = 0;
	while(str[i] && (str[i] == ' ' || str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num *neg);
}

void	init_stack(stackys **a, char **av, bool ac)
{
	long nb;
	int i;

	i = 0;
	while(av[i])
	{
		if (syntax_fix(av[i]))
			free_mystake(a, av, ac);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_mystake(a, av, ac);
		if (repeat_error(*a, (int)nb))
			repeat_error(a, av, ac);
		
	}
}