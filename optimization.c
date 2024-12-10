/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:49:51 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/10 14:49:25 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Function prototypes for command optimization */
void			add_command(t_cmd_buffer *cmd_buf, char *cmd);
void			flush_commands(t_cmd_buffer *cmd_buf);
static void		optimize_commands(t_cmd_buffer *cmd_buf);
static int		is_command_pair(t_cmd_buffer *cmd_buf,
					char *cmd1, char *cmd2, int index);
static void		replace_commands(t_cmd_buffer *cmd_buf,
					char *new_cmd, int index);

/* Add a command to the global buffer */
void	add_command(t_cmd_buffer *cmd_buf, char *cmd)
{
	if (cmd_buf->index < cmd_buf->size)
		cmd_buf->commands[cmd_buf->index++] = ft_strdup(cmd);
	else
	{
		flush_commands(cmd_buf);
		cmd_buf->commands[0] = ft_strdup(cmd);
		cmd_buf->index = 1;
	}
}

/* Flush and print optimized commands */
void	flush_commands(t_cmd_buffer *cmd_buf)
{
	int	i;

	optimize_commands(cmd_buf);
	i = 0;
	while (i < cmd_buf->index)
	{
		if (cmd_buf->commands[i] != NULL
			&& ft_strncmp(cmd_buf->commands[i], "0", 1) != 0)
			ft_printf("%s\n", cmd_buf->commands[i]);
		free(cmd_buf->commands[i]);
		cmd_buf->commands[i] = NULL;
		i++;
	}
	cmd_buf->index = 0;
}

/* Optimize command sequences by combining or canceling commands */
static void	optimize_commands(t_cmd_buffer *cmd_buf)
{
	int	i;

	i = 0;
	while (i < cmd_buf->index - 1)
	{
		if (is_command_pair(cmd_buf, "sa", "sb", i)
			|| is_command_pair(cmd_buf, "sb", "sa", i))
			replace_commands(cmd_buf, "ss", i);
		else if (is_command_pair(cmd_buf, "ra", "rb", i)
			|| is_command_pair(cmd_buf, "rb", "ra", i))
			replace_commands(cmd_buf, "rr", i);
		else if (is_command_pair(cmd_buf, "rra", "rrb", i)
			|| is_command_pair(cmd_buf, "rrb", "rra", i))
			replace_commands(cmd_buf, "rrr", i);
		else if (is_command_pair(cmd_buf, "rra", "ra", i)
			|| is_command_pair(cmd_buf, "ra", "rra", i))
			replace_commands(cmd_buf, "", i);
		else if (is_command_pair(cmd_buf, "rrb", "rb", i)
			|| is_command_pair(cmd_buf, "rb", "rrb", i))
			replace_commands(cmd_buf, "", i);
		i++;
	}
}

/* Check if two consecutive commands form a specific pair */
static int	is_command_pair(t_cmd_buffer *cmd_buf,
				char *cmd1, char *cmd2, int index)
{
	return (ft_strncmp(cmd_buf->commands[index], cmd1, ft_strlen(cmd1)) == 0
		&& ft_strncmp(cmd_buf->commands[index + 1], cmd2,
			ft_strlen(cmd2)) == 0);
}

/* Replace two consecutive commands with an optimized command */
static void	replace_commands(t_cmd_buffer *cmd_buf, char *new_cmd, int index)
{
	free(cmd_buf->commands[index]);
	cmd_buf->commands[index] = ft_strdup(new_cmd);
	free(cmd_buf->commands[index + 1]);
	cmd_buf->commands[index + 1] = ft_strdup("0");
}
