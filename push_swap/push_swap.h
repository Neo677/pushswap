// header

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
void				free_mystake(stackys **stack, char **av, bool fl_ac);
int					syntax_fix(char *str_nb);
int					repeat_error(stackys *ar, int nb);

// 				output ligne par ligne etc ...
char				**ft_split(char *str, char sp);

//				verifier qu'on depasse pas, comme au coloriage
void				init_stack(stackys **a, char **av, bool ac);

//				initailiser mes stack
void				suivi_de_pos(stackys *stack);
void				price(stackys *stack_a, stackys *stack_b);
void				cheap(stackys *stack_b);
void				init_vl(stackys *stack_b, stackys *stack_a);

bool				sortie_stack(stackys *stack);
void				tiny(stackys **stack_a);
void				five(stackys **stack_a, stackys **stack_b);
void	end_R(stackys **stack, stackys *top, char name);
void	push_swap(stackys **stack_a, stackys **stack_b);
//				commande swap
void				sa(stackys **a, bool checker);
void				sb(stackys **b, bool checker);
void				ss(stackys **a, stackys **b, bool checker);

//				commande RR
void				ra(stackys **a, bool check);
void				rb(stackys **b, bool check);
void				rr(stackys **a, stackys **b, bool check);

//				reverse rotate
void				rra(stackys **satck_a, bool check);
void				rrb(stackys **stack_b, bool check);
void				rrr(stackys **stack_a, stackys **stack_b, bool check);

void				pa(stackys **stack_a, stackys **stack_b, bool checker);
void				pb(stackys **stack_a, stackys **stack_b, bool checker);
void				pb(stackys **stack_a, stackys **stack_b, bool checker);
void				end_R(stackys **stack, stackys *top, char name);

// 				commande for swap numbers
stackys				*discover_last_lone(stackys *top);
void				look_lst_node(stackys **stack, int nb);
stackys				*find_smallest(stackys *stack);
stackys				*return_less(stackys *stack);
int					stack_len(stackys *stack);

#endif