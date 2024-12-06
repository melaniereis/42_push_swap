/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:10:57 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/06 13:12:41 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	int				position;

	position = 0;
	current = a;
	while (current)
	{
		current->position = position++;
		current = current->next_node;
	}
	position = 0;
	current = b;
	while (current)
	{
		current->position = position++;
		current = current->next_node;
	}
}

/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
void    set_target_node_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next_node;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_lowest_node(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

void    set_costs(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *curr_a;
    t_stack_node *curr_b;
    
    curr_a = a;
    while (curr_a)
    {
        curr_a->cost_a = curr_a->position;
        curr_a = curr_a->next_node;
    }
    curr_b = b;
    while (curr_b)
    {
        curr_b->cost_b = curr_b->position;
        curr_b->cost_a = curr_b->target_node->position;
        curr_b = curr_b->next_node;
    }
}

void set_best_cost_optimized(t_stack_node *a, t_stack_node *b)
{
    int size_a;
    int size_b;
    int cost_ra_rb;
    int cost_rra_rrb;
    int cost_ra_rrb;
    int cost_rb_rra;
    t_stack_node *curr_b;

    curr_b = b;
    size_a = stack_len(a);
    size_b = stack_len(b);
    while (curr_b)
    {
        cost_ra_rb = ft_max_int(curr_b->cost_a, curr_b->cost_b);
        cost_rra_rrb = ft_max_int(size_a - curr_b->cost_a, size_b - curr_b->cost_b);
        cost_ra_rrb = curr_b->cost_a + (size_b - curr_b->cost_b);
        cost_rb_rra = curr_b->cost_b + (size_a - curr_b->cost_a);
        curr_b->best_cost = ft_find_min_cost(cost_ra_rb, cost_rra_rrb, cost_ra_rrb, cost_rb_rra);
        set_initial_moves(curr_b, cost_ra_rb, cost_rra_rrb, cost_ra_rrb, cost_rb_rra);
        curr_b = curr_b->next_node;
        
    }
}

void	set_initial_moves(t_stack_node *b, int cost_ra_rb, int cost_rra_rrb, int cost_ra_rrb, int cost_rb_rra)
{
	if (b->best_cost == cost_ra_rb)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RB";
	}
	else if (b->best_cost == cost_rra_rrb)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RRA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RRB";
	}
	else if (b->best_cost == cost_ra_rrb)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RRB";
	}
	else if (b->best_cost == cost_rb_rra)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RRA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RB";
	}
}
