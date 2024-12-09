/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:12:01 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 16:49:49 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts three elements in stack A.
*/
void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next_node == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next_node->value)
		sa(a);
}

/*
** Sorts five elements by moving the two lowest elements to stack B and 
** then sorting stack A with three elements before pushing them back.
*/
void	sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *lowest;
	t_stack_node *second_lowest;
	int stack_size;

	stack_size = stack_len(*a);
	lowest = find_lowest_node(*a);
	second_lowest = find_second_lowest_node(*a);
	while (*a != lowest)
	{
		if (lowest->position <= stack_size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
	while (*a != second_lowest)
	{
		if (second_lowest->position <= (stack_size - 1) / 2)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

/*
** Orchestrates the sorting of stacks A and B based on the provided size.
*/
void	sort_stacks(t_stack_node **a, t_stack_node **b, int size)
{	
	phase_one(a, b, size);
	flush_commands();
	phase_two(a, b);
	flush_commands();
	phase_three(a, size);
	flush_commands();
}
