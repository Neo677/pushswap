/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:20:36 by thobenel          #+#    #+#             */
/*   Updated: 2024/06/26 19:01:09 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }
    
    Stack *stack_a = init_stack(argc - 1);
    Stack *stack_b = init_stack(argc - 1);
    
    int i = 1;
    while (i < argc) {
        push(stack_a, atoi(argv[i]));
        i++;
    }

    printf("Avant le tri:\n");
    print_stacks(stack_a, stack_b);

    push_swap(stack_a);

    printf("\nAprès le tri:\n");
    print_stacks(stack_a, stack_b);

    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}
