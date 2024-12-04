/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:09:59 by meferraz          #+#    #+#             */
/*   Updated: 2024/11/28 16:27:27 by meferraz         ###   ########.fr       */
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
	
	set_indices(a);
	phase_one(a, b, size);
	phase_two(a, b);
	/*current = *a;
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	phase_three(a, size);*/
}

void phase_one(t_stack_node **a, t_stack_node **b, int total_size)
{
    int lowest_third;
	int	middle_third;
	int two_thirds;
	int third_largest_value;

	third_largest_value = get_third_largest_value(*a);
    while (total_size > 3 && !is_stack_sorted(*a))
    {
		two_thirds = total_size / 3 * 2;
		lowest_third = get_third_lowest_avg_value(*a);
		middle_third = get_third_middle_avg_value(*a);
		while (two_thirds && total_size > 3 && !is_stack_sorted(*a))
		{
			if ((*a)->index <= middle_third && (*a) -> value < third_largest_value)  // Push elements in lower 2/3 range to b
        	{
           		pb(b, a);  // Push element from 'a' to 'b'
				two_thirds--;
            	total_size--;
            	if ((*b) -> next_node && (*b)->index <= lowest_third)
        			rb(b);
        	}
        	else
            	ra(a);  // Rotate 'a' to bring smaller elements to the front      
		}
    }
    // Sort the last 3 elements if needed
    if(!is_stack_sorted(*a))
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
		t_stack_node *current;
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
		printf("%d\n", current_b -> value);
		current_b = current_b -> next_node;
	}
	printf("--------------------\n");
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
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next_node;
	}
}

/*
 * Find the smallest value node
*/
t_stack_node	*find_smallest(t_stack_node *stack)
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next_node;
	}
	return (smallest_node);
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

void    set_best_cost_optimized(t_stack_node *a, t_stack_node *b)
{
    int		size_a;
	int		size_b;
	int     cost_ra_rb;
    int     cost_rra_rrb;
    int     cost_ra_rrb;
    int     cost_rb_rra;

	size_a = stack_len(a);
	size_b = stack_len(b);
    cost_ra_rb = ft_max_int(b->cost_a, b->cost_b);
    cost_rra_rrb = ft_max_int(size_a - b->cost_a, size_b - b->cost_b);
    cost_ra_rrb = b->cost_a + (size_b - b->cost_b);
    cost_rb_rra = b->cost_b + (size_a - b->cost_a);
    b->best_cost = ft_find_min_cost(cost_ra_rb, cost_rra_rrb, cost_ra_rrb, cost_rb_rra);
	set_initial_moves(b, cost_ra_rb, cost_rra_rrb, cost_ra_rrb, cost_rb_rra);
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

#define HOLD    0
#define RA      1  // Rotate A
#define RB      2  // Rotate B
#define RRA     3  // Reverse Rotate A
#define RRB     4  // Reverse Rotate B

void	set_initial_moves(t_stack_node *b, int cost_ra_rb, int cost_rra_rrb, int cost_ra_rrb, int cost_rb_rra)
{
	if (b->best_cost == cost_ra_rb)
	{
		if (b->target_node->position == 0)
			b->move_a = HOLD;
		else
			b->move_a = RA;
		if (b->position == 0)
			b->move_b = HOLD;
		else
			b->move_b = RB;
	}
	else if (b->best_cost == cost_rra_rrb)
	{
		if (b->target_node->position == 0)
			b->move_a = HOLD;
		else
			b->move_a = RRA;
		if (b->position == 0)
			b->move_b = HOLD;
		else
			b->move_b = RRB;
	}
	else if (b->best_cost == cost_ra_rrb)
	{
		if (b->target_node->position == 0)
			b->move_a = HOLD;
		else
			b->move_a = RA;
		if (b->position == 0)
			b->move_b = HOLD;
		else
			b->move_b = RRB;
	}
	else if (b->best_cost == cost_rb_rra)
	{
		if (b->target_node->position == 0)
			b->move_a = HOLD;
		else
			b->move_a = RRA;
		if (b->position == 0)
			b->move_b = HOLD;
		else
			b->move_b = RB;
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
	while (best_node->position != 0 || best_node->target_node->position != 0)
	{
		if (best_node->move_a == RA)
			ra(a);
		else if (best_node->move_a == RRA)
			rra(a);
		if (best_node->move_b == RB)
			rb(b);
		else if (best_node->move_a == RRB)
			rrb(b);
		set_positions(*a, *b);
		update_moves(best_node);
	}
}

void	update_moves(t_stack_node *best_node)
{
	if (best_node->position == 0)
		best_node->move_b = HOLD;
	if (best_node->target_node->position == 0)
		best_node->move_a = HOLD;
}

void	phase_three(t_stack_node **a, int size)
{
	int	min_pos;
	
	min_pos = (*a)->position;
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(a);
			min_pos--;
		}
	}
}