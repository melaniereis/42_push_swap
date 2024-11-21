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
#include "libft/includes/libft.h"

static t_stack_node	find_last_node(t_stack_node *head);

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node *node;
	t_stack_node *last_node;

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

static t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head -> next_node)
		head = head -> next_node;
	return (head);
}
