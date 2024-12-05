/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/05 16:37:49 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*last;
	t_stack_node	*new_last;

	if (!stack || !*stack)
		return ;
	if ((*stack)->next_node == NULL)
		return ;
	head = *stack;
	last = find_last_node(*stack);
	last -> next_node = head;
	new_last = last -> prev_node;
	new_last -> next_node = NULL;
	*stack = last;
	(*stack)->prev_node = NULL;
	head -> prev_node = last;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	add_command("rra");
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	add_command("rrb");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	add_command("rrr");
}
