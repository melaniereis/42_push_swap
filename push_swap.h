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
#define PUSH_SWAP_H

#include <limits.h>

typedef struct	s_stack_node
{
	int	value;
	int	current_position;
	int	final_index;
	int	push_price;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node *target_node;
	struct	s_stack_node *next_node;
	struct	s_stack_node *prev_node;
}		t_stack_node;

static t_stack_node	find_last_node(t_stack_node *head);
void	append_node(t_stack_node **stack, int nbr);
int	error_digit_and_sign(char *str_nb);
int	error_repetition(t_stack_node *a, int nb);

#endif
