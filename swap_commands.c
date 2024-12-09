/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:54:42 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 16:54:50 by meferraz         ###   ########.fr       */
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
void	sa(t_stack_node **a)
{
	swap(a);
	add_command("sa");
}

/*
** Swaps the top two elements of stack B and records
** the operation in command history.
*/
void	sb(t_stack_node **b)
{
	swap(b);
	add_command("sb");
}

/*
** Swaps the top two elements of both stacks A and B and
** records the operation in command history.
*/
void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
	add_command("ss");
}
