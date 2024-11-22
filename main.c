/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:58:37 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/21 15:33:32 by meferraz         ###   ########.fr       */
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
	sa(&a);
	while(a)
	{
		ft_printf("%d\n", a -> value);
		a = a -> next_node;
	}
	free_stack(&a);
	if (split_flag)
		free_matrix(argv);
	return (0);
}
