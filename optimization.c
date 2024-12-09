/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:49:51 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 14:45:18 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define CMD_BUFFER_SIZE 100

/* Function prototypes for command optimization */
void		add_command(char *cmd);
void		flush_commands(void);
static void	optimize_commands(void);
static int	is_command_pair(char *cmd1, char *cmd2, int index);
static void	replace_commands(char *new_cmd, int index);

/* Global command buffer to store and optimize commands */
static char	*g_cmd_buffer[CMD_BUFFER_SIZE];
static int	g_cmd_index = 0;

/* Add a command to the global buffer */
void	add_command(char *cmd)
{
	if (g_cmd_index < CMD_BUFFER_SIZE)
		g_cmd_buffer[g_cmd_index++] = ft_strdup(cmd);
	else
	{
		flush_commands();
		g_cmd_buffer[0] = ft_strdup(cmd);
		g_cmd_index = 1;
	}
}

/* Flush and print optimized commands */
void	flush_commands(void)
{
	int	i;

	optimize_commands();
	i = 0;
	while (i < g_cmd_index)
	{
		if (g_cmd_buffer[i] != NULL && ft_strncmp(g_cmd_buffer[i], "0", 1) != 0)
			ft_printf("%s\n", g_cmd_buffer[i]);
		free(g_cmd_buffer[i]);
		g_cmd_buffer[i] = NULL;
		i++;
	}
	g_cmd_index = 0;
}

/* Optimize command sequences by combining or canceling commands */
static void	optimize_commands(void)
{
	int	i;

	i = 0;
	while (i < g_cmd_index - 1)
	{
		if (is_command_pair("sa", "sb", i)
			|| is_command_pair("sb", "sa", i))
			replace_commands("ss", i);
		else if (is_command_pair("ra", "rb", i)
			|| is_command_pair("rb", "ra", i))
			replace_commands("rr", i);
		else if (is_command_pair("rra", "rrb", i)
			|| is_command_pair("rrb", "rra", i))
			replace_commands("rrr", i);
		else if (is_command_pair("rra", "ra", i)
			|| is_command_pair("ra", "rra", i))
			replace_commands("", i);
		else if (is_command_pair("rrb", "rb", i)
			|| is_command_pair("rb", "rrb", i))
			replace_commands("", i);
		i++;
	}
}

/* Check if two consecutive commands form a specific pair */
static int	is_command_pair(char *cmd1, char *cmd2, int index)
{
	return (ft_strncmp(g_cmd_buffer[index], cmd1, ft_strlen(cmd1)) == 0
		&& ft_strncmp(g_cmd_buffer[index + 1], cmd2, ft_strlen(cmd2)) == 0);
}

/* Replace two consecutive commands with an optimized command */
static void	replace_commands(char *new_cmd, int index)
{
	free(g_cmd_buffer[index]);
	g_cmd_buffer[index] = ft_strdup(new_cmd);
	free(g_cmd_buffer[index + 1]);
	g_cmd_buffer[index + 1] = ft_strdup("0");
}
