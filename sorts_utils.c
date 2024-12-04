/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:26:39 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/04 16:01:19 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack_node *find_lowest_node(t_stack_node *a)
{
    long    lowest;
    t_stack_node    *lowest_node;

    if (!a)
        return (NULL);
    lowest_node = NULL;
    lowest = INT_MAX;
    while (a)
    {
        if (a -> value < lowest)
        {
            lowest = a -> value;
            lowest_node = a;
        }
        a = a -> next_node;
    }
    return (lowest_node);
}

t_stack_node *find_second_lowest_node(t_stack_node *a)
{
    long    second_lowest;
    t_stack_node    *second_lowest_node;
    t_stack_node    *lowest_node;
    
    lowest_node = find_lowest_node(a);
    if (!lowest_node)
        return (NULL);
    second_lowest_node = NULL;
    second_lowest = INT_MAX;
    while (a)
    {
        if (a != lowest_node && a->value < second_lowest)
        {
            second_lowest = a->value;
            second_lowest_node = a;
        }
        a = a->next_node;
    }
    return (second_lowest_node);
}
