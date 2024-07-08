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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct stack_node
{
	int 	 value;
	int		position;
	int last_node;
	int push_pr;
	bool median;
	bool	cheaper;
	struct stack_node *target;
	struct stack_node *next_one;
	struct stack_node *previous_node;
}				stack_node;


#endif
