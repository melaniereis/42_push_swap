/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:49:51 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/05 16:59:49 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define CMD_BUFFER_SIZE 3

// Function declarations
void add_command(char *cmd);
void flush_commands(void);
void optimize_commands(void);
void optimize_two_commands(void);
void optimize_three_commands(void);
int is_command_pair(char *cmd1, char *cmd2);
int is_command_sequence(char *cmd1, char *cmd2, char *cmd3);
void replace_commands(char *new_cmd);

// Global command buffer
static char *g_cmd_buffer[CMD_BUFFER_SIZE];
static int g_cmd_index = 0;

// Function definitions
void add_command(char *cmd)
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

void flush_commands(void)
{
    optimize_commands();
    int i = 0;
    while (i < g_cmd_index)
    {
        ft_printf("%s\n", g_cmd_buffer[i]);
        free(g_cmd_buffer[i]);
        i++;
    }
    g_cmd_index = 0;
}

void optimize_commands(void)
{
    if (g_cmd_index == 2)
        optimize_two_commands();
    else if (g_cmd_index == 3)
        optimize_three_commands();
}

void optimize_two_commands(void)
{
    if ((is_command_pair("sa", "sb")) || (is_command_pair("sb", "sa")))
        replace_commands("ss");
    else if ((is_command_pair("ra", "rb")) || (is_command_pair("rb", "ra")))
        replace_commands("rr");
    else if ((is_command_pair("rra", "rrb")) || (is_command_pair("rrb", "rra")))
        replace_commands("rrr");
}

void optimize_three_commands(void)
{
    if (is_command_sequence("pb", "ra", "pa"))
        replace_commands("sa");
    else if (is_command_sequence("pa", "rb", "pb"))
        replace_commands("sb");
}

int is_command_pair(char *cmd1, char *cmd2)
{
    return (ft_strncmp(g_cmd_buffer[0], cmd1, ft_strlen(cmd1)) == 0 && 
            ft_strncmp(g_cmd_buffer[1], cmd2, ft_strlen(cmd2)) == 0);
}

int is_command_sequence(char *cmd1, char *cmd2, char *cmd3)
{
    return (ft_strncmp(g_cmd_buffer[0], cmd1, ft_strlen(cmd1)) == 0 &&
            ft_strncmp(g_cmd_buffer[1], cmd2, ft_strlen(cmd2)) == 0 &&
            ft_strncmp(g_cmd_buffer[2], cmd3, ft_strlen(cmd3)) == 0);
}

void replace_commands(char *new_cmd)
{
    int i = 0;
    while (i < g_cmd_index)
        free(g_cmd_buffer[i++]);
    
    g_cmd_buffer[0] = ft_strdup(new_cmd);
    g_cmd_index = 1;
}