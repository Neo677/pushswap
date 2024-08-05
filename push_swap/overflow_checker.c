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
	while ((str[i] && str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
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

void	init_stack(t_stackys **a, char **av, bool ac)
{
	long	nb;
	int		i;

	i = 0;
	while (av[i])
	{	
		if (syntax_fix(av[i]))
			free_mystake(a, av, ac);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_mystake(a, av, ac);
		if (repeat_error(*a, (int)nb))
			free_mystake(a, av, ac);
		look_lst_node(a, (int)nb);
		i++;
	}
	if (ac)
		free_thbackgrd(av);
}
