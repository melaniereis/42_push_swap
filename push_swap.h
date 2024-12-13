/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/12 10:07:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

# define CMD_BUFFER_SIZE 100 // Buffer size for command storage

// Structure representing a node in the stack
typedef struct s_stack_node
{
	int					value;// Value of the node
	int					index;// Index for sorting purposes
	int					position;// Position in the stack
	int					cost_a;// Cost of moving to stack A
	int					cost_b;// Cost of moving to stack B
	int					best_cost;// Best cost calculated for moves
	char				*move_a;// Move command for stack A
	char				*move_b;// Move command for stack B
	struct s_stack_node	*target_node;// Target node for operations
	struct s_stack_node	*next_node;// Pointer to the next node in the stack
	struct s_stack_node	*prev_node;// Pointer to the previous node in the stack
}	t_stack_node;

// Structure representing buffer to store move commands
typedef struct s_cmd_buffer
{
	char	**commands;
	int		index;
	int		size;
}	t_cmd_buffer;

// Structure representing a data of costs for different moves
typedef struct s_cost
{
	int	ra_rb;
	int	rra_rrb;
	int	ra_rrb;
	int	rb_rra;
}	t_cost;

// Stack initialization and management functions
void			stack_init(t_stack_node **a, char **argv, int split_flag,
					t_cmd_buffer *cmd_buf);
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_last_node(t_stack_node *head);
int				is_stack_sorted(t_stack_node *head);
int				stack_len(t_stack_node *head);

// Error & free handling functions
int				error_digit_and_sign(char *str_nb);
int				error_repetition(t_stack_node *a, int nb);
void			free_matrix(char **argv);
void			free_stack(t_stack_node **stack);
void			free_all_message(t_stack_node **a, char **argv, int split_flag,
					t_cmd_buffer *cmd_buf);
void			free_cmd_buffer(t_cmd_buffer *cmd_buf);
// Basic operations on stacks
void			sa(t_stack_node **a, t_cmd_buffer *cmd_buf);
void			sb(t_stack_node **b, t_cmd_buffer *cmd_buf);
void			ss(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf);

void			pa(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf);
void			pb(t_stack_node **b, t_stack_node **a, t_cmd_buffer *cmd_buf);

void			ra(t_stack_node **a, t_cmd_buffer *cmd_buf);
void			rb(t_stack_node **b, t_cmd_buffer *cmd_buf);
void			rr(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf);

void			rra(t_stack_node **a, t_cmd_buffer *cmd_buf);
void			rrb(t_stack_node **b, t_cmd_buffer *cmd_buf);
void			rrr(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf);

// Sorting functions for specific cases
void			sort_three(t_stack_node **a, t_cmd_buffer *cmd_buf);
void			sort_five(t_stack_node **a, t_stack_node **b,
					t_cmd_buffer *cmd_buf);

// Node finding functions for sorting purposes
t_stack_node	*find_highest_node(t_stack_node *a);
t_stack_node	*find_lowest_node(t_stack_node *a);
t_stack_node	*find_second_lowest_node(t_stack_node *a);

// Main sorting function that orchestrates sorting between two stacks
void			sort_stacks(t_stack_node **a, t_stack_node **b,
					int size, t_cmd_buffer *cmd_buf);

// Phase functions for sorting algorithm implementation
void			phase_one(t_stack_node **a, t_stack_node **b,
					int total_size, t_cmd_buffer *cmd_buf);
void			phase_two(t_stack_node **a, t_stack_node **b,
					t_cmd_buffer *cmd_buf);
void			phase_three(t_stack_node **a, int size, t_cmd_buffer *cmd_buf);

// Functions for setting indices and calculating costs for moves
void			set_indices(t_stack_node **a);
void			set_positions(t_stack_node *a, t_stack_node *b);
void			set_target_node_for_b(t_stack_node *a, t_stack_node *b);
void			set_costs(t_stack_node *a, t_stack_node *b);
void			set_best_cost_optimized(t_stack_node *a, t_stack_node *b);
void			set_initial_moves(t_stack_node *b, t_cost *cost);

// Utility functions for cost calculations and command management
int				ft_max_int(int a, int b);
int				ft_find_min_cost(int a, int b, int c, int d);

// Command management functions for tracking operations performed during sorting
void			add_command(t_cmd_buffer *cmd_buf, char *cmd);
void			flush_commands(t_cmd_buffer *cmd_buf);

#endif /* PUSH_SWAP_H */
