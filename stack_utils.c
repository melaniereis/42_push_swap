/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:39:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/10 14:50:47 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head);

/*
** Creates a new node with the given value and initializes its attributes.
*/
static t_stack_node	*create_node(int nbr)
{
	t_stack_node	*node;

	node = malloc(sizeof(t_stack_node));
	if (!node)
		return (NULL);
	node->value = nbr;
	node->position = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->best_cost = 0;
	node->move_a = NULL;
	node->move_b = NULL;
	node->target_node = NULL;
	node->next_node = NULL;
	return (node);
}

/*
** Appends a new node with the given value to the end of the stack.
*/
void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = create_node(nbr);
	if (!node)
		return ;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next_node = node;
		node->prev_node = last_node;
	}
}

/*
** Finds and returns the last node in the stack.
*/
t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next_node)
		head = head->next_node;
	return (head);
}

/*
** Checks if the stack is sorted in ascending order.
*/
int	is_stack_sorted(t_stack_node *head)
{
	if (head == NULL)
		return (1);
	while (head->next_node)
	{
		if (head->value > head->next_node->value)
			return (0);
		head = head->next_node;
	}
	return (1);
}

/*
** Returns the number of nodes in the stack.
*/
int	stack_len(t_stack_node *head)
{
	int	counter;

	counter = 0;
	if (head == NULL)
		return (counter);
	while (head)
	{
		counter++;
		head = head->next_node;
	}
	return (counter);
}
