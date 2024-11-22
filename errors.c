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

int	error_digit_and_sign(char *str_nb)
{
	int	i;

	i = 0;
	if ((str_nb[0] == '+') || (str_nb[0] == '-'))
	{
		i++;
		if (!ft_isdigit(str_nb[i]))
			return (1);
	}
	while (str_nb[i] != '\0')
	{
		if (!ft_isdigit(str_nb[i]))
			return (1);
		i++;
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
	int	i;

	if (argv == NULL)
		return ;
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current -> next_node;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_all_message(t_stack_node **a, char **argv, int split_flag)
{
	free_stack(a);
	if (argv != NULL && split_flag)
		free_matrix(argv);
	write(1, "Error\n", 6);
	exit(1);
}
