/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:58:37 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/12 10:41:22 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_cmd_buffer(t_cmd_buffer *cmd_buf)
{
	cmd_buf->size = CMD_BUFFER_SIZE;
	cmd_buf->index = 0;
	cmd_buf->commands = (char **)malloc(sizeof(char *) * cmd_buf->size);
	if (!cmd_buf->commands)
		exit(1);
}

void	free_cmd_buffer(t_cmd_buffer *cmd_buf)
{
	if (cmd_buf->commands)
		free(cmd_buf->commands);
	cmd_buf->commands = NULL;
}

static void	sort_if_needed(t_stack_node **a,
	t_stack_node **b, t_cmd_buffer *cmd_buf)
{
	int	len;

	if (!is_stack_sorted(*a))
	{
		len = stack_len(*a);
		if (len == 2 && (*a)->value > (*a)->next_node->value)
			sa(a, cmd_buf);
		else if (len == 3)
			sort_three(a, cmd_buf);
		else if (len == 5)
			sort_five(a, b, cmd_buf);
		else if (len > 3)
			sort_stacks(a, b, len, cmd_buf);
		flush_commands(cmd_buf);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				split_flag;
	t_cmd_buffer	cmd_buf;

	a = NULL;
	b = NULL;
	split_flag = 0;
	if (argc == 1)
		return (1);
	init_cmd_buffer(&cmd_buf);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		split_flag = 1;
		stack_init(&a, argv, split_flag, &cmd_buf);
	}
	else
		stack_init(&a, argv + 1, split_flag, &cmd_buf);
	sort_if_needed(&a, &b, &cmd_buf);
	free_stack(&a);
	free_stack(&b);
	if (split_flag)
		free_matrix(argv);
	return (free_cmd_buffer(&cmd_buf), 0);
}
