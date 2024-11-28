/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:00:00 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/21 14:54:24 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	//bool	above_median;
	//bool	cheapest;
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

void    tiny_sort(t_stack_node **a);
t_stack_node *find_highest_node(t_stack_node *a);
#endif

