/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:09:59 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/06 13:21:32 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void phase_one(t_stack_node **a, t_stack_node **b, int total_size)
{
    int lowest_third;
    int middle_third;
    int two_thirds;
    int third_largest_index;

    while (total_size > 3 && !is_stack_sorted(*a))
    {
        two_thirds = total_size / 3 * 2;
        lowest_third = total_size / 3;
        middle_third = 2 * total_size / 3;
        third_largest_index = total_size - 3;
		set_indices(a);

        while (two_thirds && total_size > 3 && !is_stack_sorted(*a))
        {
            if ((*a)->index < middle_third && (*a)->index < third_largest_index)
            {
                pb(b, a);
                two_thirds--;
                total_size--;
                if ((*b)->next_node && (*b)->index < lowest_third)
                    rb(b);
            }
            else
                ra(a);
        }
    }

    if (!is_stack_sorted(*a))
        sort_three(a);
}
