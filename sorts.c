/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:12:01 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/04 15:59:46 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack_node **a)
{
    t_stack_node    *highest_node;
    
    highest_node = find_highest_node(*a);
    if (*a == highest_node)
    	ra(a);
    else if ((*a)->next_node == highest_node)
    	rra(a);
    if ((*a)->value > (*a)->next_node->value)
    	sa(a);
}
void    sort_five(t_stack_node **a, t_stack_node **b)
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
