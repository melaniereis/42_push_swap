/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:31:45 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 16:41:32 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Transfers the top element from the source stack to the 
** destination stack. Updates the pointers accordingly.
*/
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

/*
** Pushes the top element from stack B onto stack A and 
** records the operation in command history.
*/
void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	add_command("pa");
}

/*
** Pushes the top element from stack A onto stack B and 
** records the operation in command history.
*/
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	add_command("pb");
}
