/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:34:04 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/12 10:05:55 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if a string represents a valid integer. */
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

/* Checks for duplicate numbers in the stack. */
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

/* Frees a 2D array of strings. */
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

/* Frees a linked list of stack nodes. */
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

/* Frees the stack, matrix, and exits with an error message. */
void	free_all_message(t_stack_node **a, char **argv, int split_flag,
			t_cmd_buffer *cmd_buf)
{
	free_stack(a);
	if (argv != NULL && split_flag)
		free_matrix(argv);
	write(1, "Error\n", 6);
	free_cmd_buffer(cmd_buf);
	exit(1);
}
