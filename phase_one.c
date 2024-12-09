/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:09:59 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 17:00:40 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_stack(t_stack_node **a, t_stack_node **b, int *total_size);
void	finalize_phase_one(t_stack_node **a);

/*
** Function: phase_one
** Description: Implements the first phase of the sorting algorithm.
**              This phase partitions the stack 'a' by transferring
**              elements to stack 'b' based on their indices. It continues
**              until there are three or fewer elements left in stack 'a'.
**
** Parameters:
** - t_stack_node **a: Pointer to the source stack to be partitioned.
** - t_stack_node **b: Pointer to the dest stack where elements are pushed.
** - int total_size: The total number of elements in stack 'a'.
*/
void	phase_one(t_stack_node **a, t_stack_node **b, int total_size)
{
	while (total_size > 3 && !is_stack_sorted(*a))
	{
		partition_stack(a, b, &total_size);
	}
	finalize_phase_one(a);
}

/* Partition the stack by pushing elements from stack a to stack b */
static void	partition_stack(t_stack_node **a, t_stack_node **b, int *total_size)
{
	int	lowest_third;
	int	middle_third;
	int	two_thirds;
	int	third_largest_index;

	two_thirds = *total_size / 3 * 2;
	lowest_third = *total_size / 3;
	middle_third = 2 * *total_size / 3;
	third_largest_index = *total_size - 3;
	set_indices(a);
	while (two_thirds && *total_size > 3 && !is_stack_sorted(*a))
	{
		if ((*a)->index < middle_third && (*a)->index < third_largest_index)
		{
			pb(b, a);
			two_thirds--;
			(*total_size)--;
			if ((*b)->next_node && (*b)->index < lowest_third)
				rb(b);
		}
		else
			ra(a);
	}
}

/* Finalize phase one by sorting the remaining elements in stack a */
void	finalize_phase_one(t_stack_node **a)
{
	if (!is_stack_sorted(*a))
		sort_three(a);
}
