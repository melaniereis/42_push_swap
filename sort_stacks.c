/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:09:59 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/05 16:51:39 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_stacks(t_stack_node **a, t_stack_node **b, int size);
void    phase_one(t_stack_node **a, t_stack_node **b, int total_size);
int     get_avg_value(t_stack_node *a);
int     get_third_lowest_avg_value(t_stack_node *a);
int     get_third_middle_avg_value(t_stack_node *a);
int     get_third_largest_value(t_stack_node *a);
void    phase_two(t_stack_node **a, t_stack_node **b);
void    set_positions(t_stack_node *a, t_stack_node *b);
t_stack_node    *find_min_node(t_stack_node *stack);
void    set_target_node_for_b(t_stack_node *a, t_stack_node *b);
t_stack_node	*find_smallest(t_stack_node *stack);
void    set_costs(t_stack_node *a, t_stack_node *b);
void    set_best_cost_optimized(t_stack_node *a, t_stack_node *b);
int     ft_max_int(int a, int b);
int     ft_find_min_cost(int a, int b, int c, int d);
void    set_initial_moves(t_stack_node *b, int cost_ra_rb, int cost_rra_rrb, int cost_ra_rrb, int cost_rb_rra);
void    do_best_move(t_stack_node **a, t_stack_node **b);
void    execute_moves(t_stack_node **a, t_stack_node **b, t_stack_node *best_node);
void    update_moves(t_stack_node *best_node);
void    phase_three(t_stack_node **a, int size);

void	sort_stacks(t_stack_node **a, t_stack_node **b, int size)
{
	phase_one(a, b, size);
	flush_commands();
	phase_two(a, b);
	flush_commands();
	phase_three(a, size);
	flush_commands();
	/*t_stack_node *current;
	t_stack_node	*current_b;
	current = *a;
	printf("-------STACK A------\n");
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	printf("-------STACK B------\n");
	current_b = *b;
	while (current_b)
	{
		printf("value: %d\n", current_b -> value);
		printf("position: %d\n", current_b -> position);
		printf("cost_a: %d\n", current_b -> cost_a);
		printf("cost_b: %d\n", current_b -> cost_b);
		printf("best_cost: %d\n", current_b -> best_cost);
		printf("move_a: %s\n", current_b -> move_a);
		printf("move_b: %s\n", current_b -> move_b);
		if (current_b -> target_node != NULL)
			printf("target_node: %d\n", current_b -> target_node->value);
		else
			printf("target_node: NULL\n");
		current_b = current_b -> next_node;
		printf("****************\n");
	}
	printf("--------------------\n");*/
}

void phase_one(t_stack_node **a, t_stack_node **b, int total_size)
{
    int lowest_third;
    int middle_third;
    int two_thirds;
    int third_largest_index;

    while (total_size > 3 && !is_stack_sorted(*a))
    {
        two_thirds = total_size / 3 * 2;
        lowest_third = total_size / 3;
        middle_third = 2 * total_size / 3;
        third_largest_index = total_size - 3;
		set_indices(a);

        while (two_thirds && total_size > 3 && !is_stack_sorted(*a))
        {
            if ((*a)->index < middle_third && (*a)->index < third_largest_index)
            {
                pb(b, a);
                two_thirds--;
                total_size--;
                if ((*b)->next_node && (*b)->index < lowest_third)
                    rb(b);
            }
            else
                ra(a);
        }
    }

    if (!is_stack_sorted(*a))
        sort_three(a);
}

int get_avg_value(t_stack_node *a)
{
    int sum_values;
    int count;
    t_stack_node *tmp;

    sum_values = 0;
    count = 0;
    tmp = a;
    while (tmp != NULL)
    {
        sum_values += tmp->value;
        count++;
        tmp = tmp->next_node;
    }
    return (sum_values / count);
}

int	get_third_lowest_avg_value(t_stack_node *a)
{
	return (2 * get_avg_value(a) / 3);
}

int	get_third_middle_avg_value(t_stack_node *a)
{
	return (4 * get_avg_value(a) / 3);
}

int	get_third_largest_value(t_stack_node *a)
{
	int	first_largest;
	int	second_largest;
	int	third_largest;
	t_stack_node	*current;

	first_largest = -2147483648; // Initialize to smallest possible integer
	second_largest = -2147483648;
	third_largest = -2147483648;
	current = a;

	while (current != NULL)
	{
		if (current->value > first_largest)
		{
			third_largest = second_largest;
			second_largest = first_largest;
			first_largest = current->value;
		}
		else if (current->value > second_largest)
		{
			third_largest = second_largest;
			second_largest = current->value;
		}
		else if (current->value > third_largest)
			third_largest = current->value;
		current = current->next_node;
	}
	return (third_largest);
}

void	phase_two(t_stack_node **a, t_stack_node **b)
{	
	while (*b)
	{
		set_positions(*a, *b);
		set_target_node_for_b(*a, *b);
		set_costs(*a, *b);
		set_best_cost_optimized(*a, *b);
		do_best_move(a, b);
	}
}
void	set_positions(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	int				position;

	position = 0;
	current = a;
	while (current)
	{
		current->position = position;
		position++;
		current = current->next_node;
	}
	position = 0;
	current = b;
	while (current)
	{
		current->position = position;
		position++;
		current = current->next_node;
	}
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;
	int				min_value;

	min_node = stack;
	min_value = stack->value;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next_node;
	}
	return (min_node);
}
/*
 *	Best match is..
 *   | "The Smallest-bigger value" |
 *
 *  if no node is Bigger, best_match is the Smallest node.
 *  TLDR 
 *  With this function every node in b gets its target node in a
*/
void    set_target_node_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next_node;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_lowest_node(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

void    set_costs(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *curr_a;
    t_stack_node *curr_b;

	curr_a = a;
    while (curr_a)
    {
        curr_a->cost_a = curr_a->position;
        curr_a = curr_a->next_node;
    }
    curr_b = b;
    while (curr_b)
    {
        curr_b->cost_b = curr_b->position;
		curr_b->cost_a = curr_b->target_node->position;
        curr_b = curr_b->next_node;
    }
}

void set_best_cost_optimized(t_stack_node *a, t_stack_node *b)
{
    int size_a;
    int size_b;
    int cost_ra_rb;
    int cost_rra_rrb;
    int cost_ra_rrb;
    int cost_rb_rra;
    t_stack_node *curr_b;

    curr_b = b;
    size_a = stack_len(a);
    size_b = stack_len(b);
    while (curr_b)
    {
        cost_ra_rb = ft_max_int(curr_b->cost_a, curr_b->cost_b);
        cost_rra_rrb = ft_max_int(size_a - curr_b->cost_a, size_b - curr_b->cost_b);
        cost_ra_rrb = curr_b->cost_a + (size_b - curr_b->cost_b);
        cost_rb_rra = curr_b->cost_b + (size_a - curr_b->cost_a);
        curr_b->best_cost = ft_find_min_cost(cost_ra_rb, cost_rra_rrb, cost_ra_rrb, cost_rb_rra);
        set_initial_moves(curr_b, cost_ra_rb, cost_rra_rrb, cost_ra_rrb, cost_rb_rra);
        curr_b = curr_b->next_node;
    }
}

int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_find_min_cost(int a, int b, int c, int d) {
    int	min_value;

	min_value = a;
    if (b < min_value)
        min_value = b;
    if (c < min_value)
        min_value = c;
    if (d < min_value)
        min_value = d;
    return (min_value);
}

void	set_initial_moves(t_stack_node *b, int cost_ra_rb, int cost_rra_rrb, int cost_ra_rrb, int cost_rb_rra)
{
	if (b->best_cost == cost_ra_rb)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RB";
	}
	else if (b->best_cost == cost_rra_rrb)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RRA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RRB";
	}
	else if (b->best_cost == cost_ra_rrb)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RRB";
	}
	else if (b->best_cost == cost_rb_rra)
	{
		if (b->target_node->position == 0)
			b->move_a = "HOLD";
		else
			b->move_a = "RRA";
		if (b->position == 0)
			b->move_b = "HOLD";
		else
			b->move_b = "RB";
	}
}

void	do_best_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	t_stack_node	*best_node;
	int				best_cost;

	current = *b;
	best_node = NULL;
	best_cost = INT_MAX;
	while (current)
	{
		if (current->best_cost < best_cost)
		{
			best_cost = current->best_cost;
			best_node = current;
		}
		current = current->next_node;
	}
	execute_moves(a, b, best_node);
	pa(a, b);
}

void	execute_moves(t_stack_node **a, t_stack_node **b, t_stack_node *best_node)
{
	while (best_node->position > 0 || best_node->target_node->position > 0)
	{
		if (ft_strncmp(best_node->move_a, "RA", 2) == 0)
			ra(a);
		else if (ft_strncmp(best_node->move_a, "RRA", 3) == 0)
			rra(a);
		set_positions(*a, *b);
		if (ft_strncmp(best_node->move_a, "RB", 2) == 0)
			rb(b);
		else if (ft_strncmp(best_node->move_a, "RRB", 3) == 0)
			rrb(b);
		set_positions(*a, *b);
		update_moves(best_node);
	}
}

void	update_moves(t_stack_node *best_node)
{
	if (best_node->position == 0)
		best_node->move_b = "HOLD";
	if (best_node->target_node->position == 0)
		best_node->move_a = "HOLD";
}

void phase_three(t_stack_node **a, int size)
{
    t_stack_node *min_node;
    int min_pos;

    while (!is_stack_sorted(*a))
    {
		set_positions(*a, NULL);
        min_node = find_lowest_node(*a);
        min_pos = min_node->position;
        if (min_pos > size / 2)
            rra(a);
        else
            ra(a);
    }
}