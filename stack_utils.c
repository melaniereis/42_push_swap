/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:39:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/21 15:06:44 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*find_last_node(t_stack_node *head);

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->value = nbr;
	node->next_node = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev_node = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node -> next_node = node;
		node -> prev_node = last_node;
	}
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head -> next_node)
		head = head -> next_node;
	return (head);
}

int	is_stack_sorted(t_stack_node *head)
{
	if (head == NULL)
		return (1);
	while (head -> next_node)
	{
		if (head -> value > head -> next_node -> value)
			return (0);
		head = head -> next_node;
	}
	return (1);
}

int	stack_len(t_stack_node *head)
{
	int	counter;

	counter = 0;
	if (head == NULL)
		return (counter);
	while (head)
	{
		counter++;
		head = head -> next_node;
	}
	return (counter);
}
