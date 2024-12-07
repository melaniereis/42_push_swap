/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/05 16:51:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					position;
	int					cost_a;
	int					cost_b;
	int					best_cost;
	char				*move_a;
	char				*move_b;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next_node;
	struct s_stack_node	*prev_node;
}		t_stack_node;

void			stack_init(t_stack_node **a, char **argv, int split_flag);
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_last_node(t_stack_node *head);
int	is_stack_sorted(t_stack_node *head);
int	stack_len(t_stack_node *head);

int				error_digit_and_sign(char *str_nb);
int				error_repetition(t_stack_node *a, int nb);
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
void			free_all_message(t_stack_node **a, char **argv, int split_flag);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

void    sort_three(t_stack_node **a);
void    sort_five(t_stack_node **a, t_stack_node **b);

t_stack_node *find_highest_node(t_stack_node *a);
t_stack_node *find_lowest_node(t_stack_node *a);
t_stack_node *find_second_lowest_node(t_stack_node *a);


void	sort_stacks(t_stack_node **a, t_stack_node **b, int size);

void	phase_one(t_stack_node **a, t_stack_node **b, int total_size);
void	phase_two(t_stack_node **a, t_stack_node **b);
void	phase_three(t_stack_node **a, int size);

void	set_indices(t_stack_node **a);
void	set_positions(t_stack_node *a, t_stack_node *b);
void    set_target_node_for_b(t_stack_node *a, t_stack_node *b);
void    set_costs(t_stack_node *a, t_stack_node *b);
void set_best_cost_optimized(t_stack_node *a, t_stack_node *b);
void	set_initial_moves(t_stack_node *b, int cost_ra_rb, int cost_rra_rrb, int cost_ra_rrb, int cost_rb_rra);

int	ft_max_int(int a, int b);
int ft_find_min_cost(int a, int b, int c, int d);

void flush_commands(void);
void add_command(char *cmd);

#endif

