/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_init_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:08:53 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 17:14:15 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void set_move_commands_for_ra_rb(t_stack_node *b);
static void set_move_commands_for_rra_rrb(t_stack_node *b);
static void set_move_commands_for_ra_rrb(t_stack_node *b);
static void set_move_commands_for_rb_rra(t_stack_node *b);

/*
** Sets the initial move commands for each node in stack B based on 
** calculated costs.
*/
void	set_initial_moves(t_stack_node *b, int cost_ra_rb, 
	int cost_rra_rrb, int cost_ra_rrb, int cost_rb_rra)
{
	if (b->best_cost == cost_ra_rb)
	{
		set_move_commands_for_ra_rb(b);
	}
	else if (b->best_cost == cost_rra_rrb)
	{
		set_move_commands_for_rra_rrb(b);
	}
	else if (b->best_cost == cost_ra_rrb)
	{
		set_move_commands_for_ra_rrb(b);
	}
	else if (b->best_cost == cost_rb_rra)
	{
		set_move_commands_for_rb_rra(b);
	}
}

/*
** Sets move commands for the case where the best cost is for RA and RB.
*/
static void set_move_commands_for_ra_rb(t_stack_node *b)
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

/*
** Sets move commands for the case where the best cost is for RRA and RRB.
*/
static void set_move_commands_for_rra_rrb(t_stack_node *b)
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

/*
** Sets move commands for the case where the best cost is for RA and RRB.
*/
static void set_move_commands_for_ra_rrb(t_stack_node *b)
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

/*
** Sets move commands for the case where the best cost is for RB and RRA.
*/
static void set_move_commands_for_rb_rra(t_stack_node *b)
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
