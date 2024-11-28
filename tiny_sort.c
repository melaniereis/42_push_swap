/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:12:01 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/28 09:13:54 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    tiny_sort(t_stack_node **a)
{
    t_stack_node    *highest_node;
    
    highest_node = find_highest_node(*a);
    if (*a == highest_node)
    {
    	ra(a);
    	if ((*a)->value > (*a)->next_node->value)
    		sa(a);
    }
    else if ((*a)->next_node == highest_node)
    {
    	rra(a);
    	if ((*a)->value > (*a)->next_node->value)
    		sa(a);
    }
    else if ((*a)->value > (*a)->next_node->value)
    	sa(a);
}

t_stack_node *find_highest_node(t_stack_node *a)
{
    long    highest;
    t_stack_node    *highest_node;

    if (!a)
        return (NULL);
    highest_node = NULL;
    highest = INT_MIN;
    while (a)
    {
        if (a -> value > highest)
        {
            highest = a -> value;
            highest_node = a;
        }
        a = a -> next_node;
    }
    return (highest_node);
}
