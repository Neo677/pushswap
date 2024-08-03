/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:30:59 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:31:00 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_thbackgrd(char **av)
{
	int	i;

	i = -1;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av - 1);
}

void	free_pile(t_stackys **stack)
{
	t_stackys	*tm;
	t_stackys	*ususal;

	if (stack == NULL)
		return ;
	ususal = *stack;
	while (ususal)
	{
		tm = ususal->next_one;
		free(ususal);
		ususal = tm;
	}
	*stack = NULL;
}

void	free_mystake(t_stackys **stack, char **av, bool fl_ac)
{
	free_pile(stack);
	if (fl_ac)
		free_thbackgrd(av);
	write(2, "Error detected\n", 15);
	exit(1);
}

int	syntax_fix(char *str_nb)
{
	if (!(*str_nb == '+' || *str_nb == '-' || (*str_nb >= '0'
				&& *str_nb <= '9')))
		return (1);
	if ((*str_nb == '+' || *str_nb == '-') && (!(str_nb[1] >= '0'
				&& str_nb[1] <= '9')))
		return (-1);
	while (*str_nb)
	{
		if (!(*str_nb >= '0' || *str_nb <= '9'))
			return (1);
		str_nb++;
	}
	return (0);
}

int	repeat_error(t_stackys *ar, int nb)
{
	if (ar == NULL)
		return (0);
	while (ar)
	{
		if (ar->value == nb)
			return (1);
		ar = ar->next_one;
	}
	return (0);
}
