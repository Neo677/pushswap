/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:32:22 by thobenel          #+#    #+#             */
/*   Updated: 2024/07/18 14:59:48 by thobenel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(stackys **top)
{
	int i;

	i = stack_len(*top);
	if (*top == NULL || top == NULL || i == 1)
		return ;
	*top = (*top)->next_one;
	(*top)->previous_node->previous_node = *top;
	(*top)->previous_node->next_one = (*top);
	if ((*top)->next_one)
		(*top)->next_one->previous_node = (*top)->previous_node;
	(*top)->next_one = (*top)->previous_node;
	(*top)->previous_node = NULL;
}

void	sa(stackys **a, bool checker)
{
	swap(a);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(stackys **b, bool checker)
{
	swap(b);
	if (!checker)
		write(1, "sb\n", 3);
}

void ss(stackys **a, stackys **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		write(1, "ss\n", 3);
}
