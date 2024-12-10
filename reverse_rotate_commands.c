/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/10 14:24:07 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Performs a reverse rotation on the given stack, moving the last element 
** to the front of the stack.
*/
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
	last->next_node = head;
	new_last = last->prev_node;
	new_last->next_node = NULL;
	*stack = last;
	(*stack)->prev_node = NULL;
	head->prev_node = last;
}

/*
** Performs a reverse rotation on stack A and records the operation in 
** command history.
*/
void	rra(t_stack_node **a, t_cmd_buffer *cmd_buf)
{
	reverse_rotate(a);
	add_command(cmd_buf, "rra");
}

/*
** Performs a reverse rotation on stack B and records the operation in 
** command history.
*/
void	rrb(t_stack_node **b, t_cmd_buffer *cmd_buf)
{
	reverse_rotate(b);
	add_command(cmd_buf, "rrb");
}

/*
** Performs reverse rotations on both stacks A and B and records the 
** operation in command history.
*/
void	rrr(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf)
{
	reverse_rotate(a);
	reverse_rotate(b);
	add_command(cmd_buf, "rrr");
}
