/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:31:45 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/05 16:37:29 by meferraz         ###   ########.fr       */
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
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	add_command("pa");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	add_command("pb");
}
