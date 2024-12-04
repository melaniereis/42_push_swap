/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:31:45 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/22 13:32:02 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*first_src;

	if (!src || !*src)
		return ;
	first_src = *src;
	*src = first_src->next_node;
	if (*src)
		(*src)->prev_node = NULL;
	if (!dest || !*dest)
	{
		*dest = first_src;
		first_src->next_node = NULL;
	}
	else
	{
		first_src->next_node = *dest;
		(*dest)->prev_node = first_src;
		*dest = first_src;
	}
	first_src->prev_node = NULL;
	/*t_stack_node *current = *dest;
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("-------------------\n");*/
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	//ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	//ft_printf("pb\n");
}
