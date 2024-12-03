/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:54:42 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/22 11:56:04 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	first = *stack;
	if (!stack || !first || first -> next_node == NULL)
		return ;
	second = first -> next_node;
	third = second -> next_node;
	first -> next_node = third;
	second -> next_node = first;
	second -> prev_node = NULL;
	first -> prev_node = second;
	if (third)
		third -> prev_node = first;
	*stack = second;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}
