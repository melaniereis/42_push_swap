/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:35:36 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/22 14:35:54 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node *head;
	t_stack_node *last;

	if (!stack || !*stack)
		return ;
	if ((*stack) -> next_node == NULL)
		return ;
	head = *stack;
	last = find_last_node(*stack);
	*stack = head -> next_node;
	(*stack) -> prev_node = NULL;
	head -> next_node = NULL;
	head -> prev_node = last;
	last -> next_node = head;
}

void	ra(t_stack_node **a)
{
	rotate(a);
}

void	rb(t_stack_node **b)
{
	rotate(b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}
