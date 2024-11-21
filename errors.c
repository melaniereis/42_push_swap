/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:34:04 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/21 17:20:05 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	error_digit_and_sign(char *str_nb)
{
	if (!(*str_nb == '+') || (*str_nb == '-') || !ft_isdigit(*str_nb))
		return (1);
	if (((*str_nb == '+') || (*str_nb == '-')) && !ft_isdigit(str_nb[1]))
		return (1);
	while (++*str_nb)
	{
		if (!ft_isdigit(*str_nb))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a -> value == nb)
			return (1);
		a = a -> next_node;
	}
	return (0);
}

void	free_matrix(char **argv)
{

}

void	free_stack(t_stack_node **stack)
{
	
}
