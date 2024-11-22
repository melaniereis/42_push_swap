/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:14:35 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/21 14:54:28 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
