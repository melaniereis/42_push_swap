/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:14:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 16:50:19 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Initializes stack A by parsing command-line arguments, checking for errors,
** and appending values to the stack.
*/
void	stack_init(t_stack_node **a, char **argv, int split_flag)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_digit_and_sign(argv[i]))
			free_all_message(a, argv, split_flag);
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			free_all_message(a, argv, split_flag);
		if (error_repetition(*a, nb))
			free_all_message(a, argv, split_flag);
		append_node(a, (int)nb);
		i++;
	}
}
