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
#include "libft/includes/libft.h"

void	stack_init(t_stack_node **a, char **argv)
{
	long	nb;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_digit_and_sign(argv[i]))
		{

		}
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{

		}
		if (error_repetition(a, nb))
		{

		}
		append_node(a, (int)nb);
		i++;
	}
}
