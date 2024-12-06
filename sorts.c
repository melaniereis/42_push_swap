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

void	sort_stacks(t_stack_node **a, t_stack_node **b, int size)
{
	phase_one(a, b, size);
	flush_commands();
	phase_two(a, b);
	flush_commands();
	phase_three(a, size);
	flush_commands();
	/*t_stack_node *current;
	t_stack_node	*current_b;
	current = *a;
	printf("-------STACK A------\n");
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	printf("-------STACK B------\n");
	current_b = *b;
	while (current_b)
	{
		printf("value: %d\n", current_b -> value);
		printf("position: %d\n", current_b -> position);
		printf("cost_a: %d\n", current_b -> cost_a);
		printf("cost_b: %d\n", current_b -> cost_b);
		printf("best_cost: %d\n", current_b -> best_cost);
		printf("move_a: %s\n", current_b -> move_a);
		printf("move_b: %s\n", current_b -> move_b);
		if (current_b -> target_node != NULL)
			printf("target_node: %d\n", current_b -> target_node->value);
		else
			printf("target_node: NULL\n");
		current_b = current_b -> next_node;
		printf("****************\n");
	}
	printf("--------------------\n");*/
}
