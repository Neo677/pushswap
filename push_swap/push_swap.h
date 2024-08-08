/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomtom <tomtom@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:32:43 by thobenel          #+#    #+#             */
/*   Updated: 2024/08/08 09:44:36 by tomtom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stackys;

//			fonction de liberation des stack
void					free_background(char **argv);
void					free_stack(t_stackys **stack);
void					error_free(t_stackys **a, char **argv,
							bool flag_argc_2);
int						error_syntax(char *str_nbr);
int						error_repetition(t_stackys *a, int nbr);

//			algorytme push swap
void					finish_rotation(t_stackys **stack,
							t_stackys *top_node, char stack_id);
void					push_swap(t_stackys **a, t_stackys **b);

//			sortie en output
char					**ft_split(char *str, char delim);

//			utils de depassement memoire
void					initialize_stack(t_stackys **a, char **argv,
							bool flag_argc_2);

int						main(int argc, char **argv);

//			initialisation de algo
void					update_current_position(t_stackys *stack);
void					calculate_cost(t_stackys *a, t_stackys *b);
void					set_cheapest(t_stackys *b);
void					initialize_nodes(t_stackys *a, t_stackys *b);

//			push fonction
void					pa(t_stackys **a, t_stackys **b, bool checker);
void					pb(t_stackys **b, t_stackys **a, bool checker);

//			rotation fonction
void					ra(t_stackys **a, bool checker);
void					rb(t_stackys **b, bool checker);
void					rr(t_stackys **a, t_stackys **b, bool checker);

//			reverse rotation fonction
void					rra(t_stackys **a, bool checker);
void					rrb(t_stackys **b, bool checker);
void					rrr(t_stackys **a, t_stackys **b, bool checker);

//			gestion des chiffre par groupe
bool					stack_sorted(t_stackys *stack);
void					tiny_sort(t_stackys **a);
void					handle_five(t_stackys **a, t_stackys **b);

//			swap fonction
void					sa(t_stackys **a, bool checker);
void					sb(t_stackys **b, bool checker);
void					ss(t_stackys **a, t_stackys **b, bool checker);

//			calcul a effectuer dans la stack
t_stackys			*get_tail_node(t_stackys *start);
void					add_node_to_stack(t_stackys **stack, int nbr);
t_stackys			*find_minimum(t_stackys *stack);
t_stackys			*locate_cheapest(t_stackys *stack);
int						count_stack_nodes(t_stackys *stack);

#endif
