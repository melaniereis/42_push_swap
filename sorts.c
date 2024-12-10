/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:12:01 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/10 15:19:49 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts three elements in stack A.
*/
void	sort_three(t_stack_node **a, t_cmd_buffer *cmd_buf)
{
	t_stack_node	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a, cmd_buf);
	else if ((*a)->next_node == highest_node)
		rra(a, cmd_buf);
	if ((*a)->value > (*a)->next_node->value)
		sa(a, cmd_buf);
}

/*
** Sorts five elements by moving the two lowest elements to stack B and 
** then sorting stack A with three elements before pushing them back.
*/
void	sort_five(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf)
{
	t_stack_node	*lowest;
	t_stack_node	*second_lowest;

	lowest = find_lowest_node(*a);
	second_lowest = find_second_lowest_node(*a);
	while (*a != lowest)
	{
		if (lowest->position <= stack_len(*a) / 2)
			ra(a, cmd_buf);
		else
			rra(a, cmd_buf);
	}
	pb(b, a, cmd_buf);
	while (*a != second_lowest)
	{
		if (second_lowest->position <= (stack_len(*a) - 1) / 2)
			ra(a, cmd_buf);
		else
			rra(a, cmd_buf);
	}
	pb(b, a, cmd_buf);
	sort_three(a, cmd_buf);
	pa(a, b, cmd_buf);
	pa(a, b, cmd_buf);
}

/*
** Orchestrates the sorting of stacks A and B based on the provided size.
*/
void	sort_stacks(t_stack_node **a, t_stack_node **b, int size,
			t_cmd_buffer *cmd_buf)
{
	phase_one(a, b, size, cmd_buf);
	flush_commands(cmd_buf);
	phase_two(a, b, cmd_buf);
	flush_commands(cmd_buf);
	phase_three(a, size, cmd_buf);
	flush_commands(cmd_buf);
}
