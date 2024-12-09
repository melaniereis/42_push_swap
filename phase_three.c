/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:07:39 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 15:43:39 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: phase_three
** Description: Sorts the stack 'a' using a three-phase algorithm.
**              This phase focuses on positioning the lowest node
**              either at the top or bottom of the stack.
**
** Parameters:
** - t_stack_node **a: Pointer to the stack to be sorted.
** - int size: The size of the stack.
*/
void	phase_three(t_stack_node **a, int size)
{
	t_stack_node	*min_node;
	int				min_pos;

	while (!is_stack_sorted(*a))
	{
		set_positions(*a, NULL);
		min_node = find_lowest_node(*a);
		min_pos = min_node->position;
		if (min_pos > size / 2)
			rra(a);
		else
			ra(a);
	}
}
