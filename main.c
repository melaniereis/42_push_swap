/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:58:37 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 14:46:36 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Handle sorting for small stacks (2, 3, or 5 elements) */
static void	handle_small_sorts(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2 && (*a)->value > (*a)->next_node->value)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 5)
		sort_five(a, b);
}

/* Process command line arguments and initialize the stack */
static void	process_args(int argc, char **argv, t_stack_node **a,
	int *split_flag)
{
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		*split_flag = 1;
		stack_init(a, argv, *split_flag);
	}
	else
		stack_init(a, argv + 1, *split_flag);
}

/* Clean up allocated memory */
static void	cleanup(t_stack_node **a, t_stack_node **b, char **argv,
	int split_flag)
{
	free_stack(a);
	free_stack(b);
	if (split_flag)
		free_matrix(argv);
}

/* Main function to handle push_swap algorithm */
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				split_flag;

	a = NULL;
	b = NULL;
	split_flag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	process_args(argc, argv, &a, &split_flag);
	if (!is_stack_sorted(a))
	{
		handle_small_sorts(&a, &b);
		if (stack_len(a) > 3)
			sort_stacks(&a, &b, stack_len(a));
	}
	cleanup(&a, &b, argv, split_flag);
	return (0);
}
