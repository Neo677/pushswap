/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <tomtom@student.42.fr>              +#+  +:+      
	+#+        */
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
	int				value;
	int				position;
	int				last_node;
	int				push_pr;
	bool			median;
	bool			cheaper;
	struct stackys	*target;
	struct stackys	*next_one;
	struct stackys	*previous_node;
}					stackys;

//				clean my own shit
void				free_thbackgrd(char **av);
void				free_pile(stackys **stack);
void				free_mystake(stackys *stack, char **av, bool fl_ac);
int					syntax_fix(char *str_nb);
int					repeat_error(stackys *ar, int nb);

// 				output ligne par ligne etc ...
static int			count_word(char *str, char sp);
char				**ft_split(char *str, char sp);
static char			*get_next_word(char *str, char sp);

// 				commande for swap numbers
stackys				*discover_last_lone(stackys *top);
void				look_lst_node(stackys **stack, int nb);
stackys				*find_smallest(stackys *stack);
stackys				*return_less(stackys *stack);
int					stack_len(stackys *stack);

//				verifier qu'on depasse pas, comme au coloriage
static long			ft_atol(const char *str);
void				init_stack(stackys **a, char **av, bool ac);

//				commande swap
static void swap(stackys **top);
void	sa(stackys **a, bool checker);
void	sb(stackys **b, bool checker);
void ss(stackys **a, stackys **b, bool checker);

//				commande RR
static void rott(stackys **stack);
void	ra(stackys **a, bool check);
void	rb(stackys **b, bool check);
void	rr(stackys **a, stackys **b, bool check);



#endif
