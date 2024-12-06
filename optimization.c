/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:49:51 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/06 10:00:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

#define CMD_BUFFER_SIZE 30

// Function prototypes
void add_command(char *cmd);
void flush_commands(void);
void optimize_commands(void);
int is_command_pair(char *cmd1, char *cmd2, int index);
void replace_commands(char *new_cmd, int index);

// Global command buffer
static char *g_cmd_buffer[CMD_BUFFER_SIZE];
static int g_cmd_index = 0;

void add_command(char *cmd) {
    if (g_cmd_index < CMD_BUFFER_SIZE) {
        g_cmd_buffer[g_cmd_index++] = strdup(cmd);
    } else {
        flush_commands();  // Flush commands when buffer is full
        g_cmd_buffer[0] = strdup(cmd);
        g_cmd_index = 1;
    }
}

void flush_commands(void) {
    optimize_commands();
    int i = 0;
    while (i < g_cmd_index) {
        if (g_cmd_buffer[i] != NULL && ft_strncmp(g_cmd_buffer[i], "0", 1) != 0) {
            ft_printf("%s\n", g_cmd_buffer[i]);
        }
        free(g_cmd_buffer[i]);
        g_cmd_buffer[i] = NULL; // Avoid dangling pointers
        i++;
    }
    g_cmd_index = 0;
}

void optimize_commands(void) {
    int i = 0;
    while (i < g_cmd_index - 1) {
        if (is_command_pair("sa", "sb", i) ||is_command_pair("sb", "sa", i)) {
            replace_commands("ss", i);
        } else if (is_command_pair("ra", "rb", i) || is_command_pair("rb", "ra", i)) {
            replace_commands("rr", i);
        } else if (is_command_pair("rra", "rrb", i) || is_command_pair("rrb", "rra", i)) {
            replace_commands("rrr", i);
        } else if (is_command_pair("rra", "ra", i) || is_command_pair("ra", "rra", i)) {
            replace_commands("", i);
        } else if (is_command_pair("rrb", "rb", i) || is_command_pair("rb", "rrb", i)) {
            replace_commands("", i);
        }
        i++;
    }
}

int is_command_pair(char *cmd1, char *cmd2, int index) 
{
    return (ft_strncmp(g_cmd_buffer[index], cmd1, strlen(cmd1)) == 0 && 
                 ft_strncmp(g_cmd_buffer[index + 1], cmd2, strlen(cmd2)) == 0);
}

void replace_commands(char *new_cmd, int index) {
    free(g_cmd_buffer[index]);
    g_cmd_buffer[index] = strdup(new_cmd);
    free(g_cmd_buffer[index + 1]);
    g_cmd_buffer[index + 1] = strdup("0");
}

