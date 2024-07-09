/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:23:19 by thobenel          #+#    #+#             */
/*   Updated: 2024/07/06 00:10:44 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct stackys
{
	int					value;
	int					position;
	int					last_node;
	int					push_pr;
	bool				median;
	bool				cheaper;
	struct stack_node	*target;
	struct stack_node	*next_one;
	struct stack_node	*previous_node;
}						stackys;

//					clean my shit
void					free_thbackgrd(char **av);
void					free_pile(stackys **stack);
void					free_mystake(stackys *stack, char **av, bool fl_ac);
int						syntax_fix(char *str_nb);
int						repeat_error(stackys *ar, int nb);

#endif
