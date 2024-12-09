/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:06:23 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 16:32:53 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_best_move(t_stack_node **a, t_stack_node **b);
static void	execute_moves(t_stack_node **a, t_stack_node **b,
				t_stack_node *best_node);
static void	update_moves(t_stack_node *best_node);

/*
** Function: phase_two
** Description: Implements the second phase of the sorting algorithm.
**              This phase processes elements in stack 'b', determining
**              the best moves to make in order to place them into stack 'a'.
**              It continues until all elements from stack 'b' are moved to
**              stack 'a'.
**
** Parameters:
** - t_stack_node **a: Pointer to the destination stack where elements from 
**   stack 'b' will be pushed.
** - t_stack_node **b: Pointer to the source stack containing elements to 
**   be processed.
*/
void	phase_two(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		set_positions(*a, *b);
		set_target_node_for_b(*a, *b);
		set_costs(*a, *b);
		set_best_cost_optimized(*a, *b);
		do_best_move(a, b);
	}
}

/*
** Identifies and executes the best move for the current element 
**              in stack 'b' based on previously calculated costs.
*/
static void	do_best_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	t_stack_node	*best_node;
	int				best_cost;

	current = *b;
	best_node = NULL;
	best_cost = INT_MAX;
	while (current)
	{
		if (current->best_cost < best_cost)
		{
			best_cost = current->best_cost;
			best_node = current;
		}
		current = current->next_node;
	}
	execute_moves(a, b, best_node);
	pa(a, b);
}

/*
** Executes a series of moves required to position the best node 
**              correctly before it can be pushed onto stack 'a'.
*/
static void	execute_moves(t_stack_node **a, t_stack_node **b,
	t_stack_node *best_node)
{
	while (best_node->position > 0 || best_node->target_node->position > 0)
	{
		if (ft_strncmp(best_node->move_a, "RA", 2) == 0)
			ra(a);
		else if (ft_strncmp(best_node->move_a, "RRA", 3) == 0)
			rra(a);
		if (ft_strncmp(best_node->move_b, "RB", 2) == 0)
			rb(b);
		else if (ft_strncmp(best_node->move_b, "RRB", 3) == 0)
			rrb(b);
		set_positions(*a, *b);
		update_moves(best_node);
	}
}

/*
** Updates move instructions for the given best node based on 
**              its position.
*/
static void	update_moves(t_stack_node *best_node)
{
	if (best_node->position == 0)
		best_node->move_b = "HOLD";
	if (best_node->target_node->position == 0)
		best_node->move_a = "HOLD";
}
