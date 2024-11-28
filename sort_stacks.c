/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:09:59 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/28 16:27:27 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;
	t_stack_node *cheapest;

	set_indices(a);
	len_a = stack_len(*a);
	while (len_a > 3 && !(is_stack_sorted(*a)))
	{
		cheapest = find_cheapest(*a);
		while (*a != cheapest)
			ra(a);
		pb(b,a);
		len_a--;
	}
	if (len_a == 3)
		sort_three(a);
	while (*b)
	{
		optimize_moves(a, b);
		move_b_to_a(a, b);
	}
	rotate_a_if_needed(a);
}

t_stack_node *find_cheapest()
