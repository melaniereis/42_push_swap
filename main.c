/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:58:37 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/04 16:00:23 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node *a;
	t_stack_node *b;
	int	split_flag;

	a = NULL;
	b = NULL;
	split_flag = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split_flag = 1;
		stack_init(&a, argv, split_flag);
	}
	else
		stack_init(&a, argv + 1, split_flag);
	if (!is_stack_sorted(a))
	{
		if (stack_len(a) == 2)
			if(a -> value > a -> next_node -> value)
				sa(&a);
		if (stack_len(a) == 3)
			sort_three(&a);
		if (stack_len(a) == 5)
			sort_five(&a, &b);
		if (stack_len(a) > 3)
			sort_stacks(&a, &b, stack_len(a));
	}
	free_stack(&a);
	free_stack(&b);
	if (split_flag)
		free_matrix(argv);
	return (0);
}
