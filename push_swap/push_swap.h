/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thobenel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:43 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/03 13:32:47 by thobenel         ###   ########.fr       */
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
}					t_stackys;

//				clean my own shit
void				free_thbackgrd(char **av);
void				free_pile(t_stackys **stack);
void				free_mystake(t_stackys **stack, char **av, bool fl_ac);
int					syntax_fix(char *str_nb);
int					repeat_error(t_stackys *ar, int nb);

// 				output ligne par ligne etc ...
char				**ft_split(char *str, char sp);

//				verifier qu'on depasse pas, comme au coloriage
void				init_stack(t_stackys **a, char **av, bool ac);

//				initailiser mes stack
void				suivi_de_pos(t_stackys *stack);
void				price(t_stackys *stack_a, t_stackys *stack_b);
void				cheap(t_stackys *stack_b);
void				init_vl(t_stackys *stack_b, t_stackys *stack_a);

bool				sortie_stack(t_stackys *stack);
void				tiny(t_stackys **stack_a);
void				five(t_stackys **stack_a, t_stackys **stack_b);
void				end_r(t_stackys **stack, t_stackys *top, char name);
void				push_swap(t_stackys **stack_a, t_stackys **stack_b);
//				commande swap
void				sa(t_stackys **a, bool checker);
void				sb(t_stackys **b, bool checker);
void				ss(t_stackys **a, t_stackys **b, bool checker);

//				commande RR
void				ra(t_stackys **a, bool check);
void				rb(t_stackys **b, bool check);
void				rr(t_stackys **a, t_stackys **b, bool check);

//				reverse rotate
void				rra(t_stackys **satck_a, bool check);
void				rrb(t_stackys **stack_b, bool check);
void				rrr(t_stackys **stack_a, t_stackys **stack_b, bool check);

void				pa(t_stackys **stack_a, t_stackys **stack_b, bool checker);
void				pb(t_stackys **stack_a, t_stackys **stack_b, bool checker);
void				pb(t_stackys **stack_a, t_stackys **stack_b, bool checker);
void				end_R(t_stackys **stack, t_stackys *top, char name);

// 				commande for swap numbers
t_stackys			*discover_last_lone(t_stackys *top);
void				look_lst_node(t_stackys **stack, int nb);
t_stackys			*find_smallest(t_stackys *stack);
t_stackys			*return_less(t_stackys *stack);
int					stack_len(t_stackys *stack);

int					main(int ac, char **av);

#endif
