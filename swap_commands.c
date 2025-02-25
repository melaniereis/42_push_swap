/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:54:42 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/10 14:31:56 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swaps the top two elements of the given stack.
*/
static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	first = *stack;
	if (!stack || !first || first->next_node == NULL)
		return ;
	second = first->next_node;
	third = second->next_node;
	first->next_node = third;
	second->next_node = first;
	second->prev_node = NULL;
	first->prev_node = second;
	if (third)
		third->prev_node = first;
	*stack = second;
}

/*
** Swaps the top two elements of stack A and records
** the operation in command history.
*/
void	sa(t_stack_node **a, t_cmd_buffer *cmd_buf)
{
	swap(a);
	add_command(cmd_buf, "sa");
}

/*
** Swaps the top two elements of stack B and records
** the operation in command history.
*/
void	sb(t_stack_node **b, t_cmd_buffer *cmd_buf)
{
	swap(b);
	add_command(cmd_buf, "sb");
}

/*
** Swaps the top two elements of both stacks A and B and
** records the operation in command history.
*/
void	ss(t_stack_node **a, t_stack_node **b, t_cmd_buffer *cmd_buf)
{
	sa(a, cmd_buf);
	sb(b, cmd_buf);
	add_command(cmd_buf, "ss");
}
