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

void phase_one(t_stack_node **a, t_stack_node **b, int total_size);
void rotate_b_if_needed(t_stack_node **b, int total_size);
void move_greater_than_avg_to_b(t_stack_node **a, t_stack_node **b);
int get_avg_value(t_stack_node *a);
void move_element_based_on_avg(t_stack_node **a, t_stack_node **b, int avg_index);
int	get_third_largest_value(t_stack_node *a);
void phase_two(t_stack_node **a, t_stack_node **b);
void set_positions(t_stack_node *a, t_stack_node *b);
void set_target_node_for_b(t_stack_node *a, t_stack_node *b);
void do_best_move(t_stack_node **a, t_stack_node **b);
t_stack_node *find_min_node(t_stack_node *stack);
void phase_three(t_stack_node **a, int size);

void	sort_stacks(t_stack_node **a, t_stack_node **b, int size)
{
	//t_stack_node *current;
	//t_stack_node	*current_b;
	set_indices(a);
	phase_one(a, b, size);
		/*current = *a;
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	current_b = *b;
	while (current_b)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	*/
	//phase_two(a, b);
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
    int pushed = 0;
    int two_thirds = total_size * 2 / 3;
    int size;
    
    size = total_size;

    // Push elements from a to b, based on their index
    while (pushed < two_thirds && total_size > 3 && !is_stack_sorted(*a))
    {
        if ((*a)->index < two_thirds)  // Push elements in lower 2/3 range to b
        {
            pb(b, a);  // Push element from 'a' to 'b'
            pushed++;
            total_size--;
            rotate_b_if_needed(b, size);  // Rotate 'b' if necessary
        }
        else
            ra(a);  // Rotate 'a' to bring smaller elements to the front      
    }

    // Move elements larger than average to 'b'
    if (total_size > 3 && !is_stack_sorted(*a))
    	move_greater_than_avg_to_b(a, b);

    // Sort the last 3 elements if needed
    if(!is_stack_sorted(*a))
        sort_three(a);
}

void rotate_b_if_needed(t_stack_node **b, int total_size)
{
    // Rotate 'b' only if it contains elements and the condition is met
    if ((*b) -> next_node && (*b)->index <= total_size / 3)
        rb(b);
}

void move_greater_than_avg_to_b(t_stack_node **a, t_stack_node **b)
{
    int avg_value;

    avg_value = get_avg_value(*a);  // Get the average value of elements in 'a'
    while (*a != NULL && stack_len(*a) > 3 && !is_stack_sorted(*a))  // Ensure we stop when only 3 elements remain in 'a'
    {
        move_element_based_on_avg(a, b, avg_value);  // Move elements based on average value
}
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

void move_element_based_on_avg(t_stack_node **a, t_stack_node **b, int avg_value)
{
    int current_value;
    int	third_largest_value;

    if (*a == NULL)
        return;
    third_largest_value = get_third_largest_value(*a);
    current_value = (*a)->value;
    if (current_value > avg_value && current_value < third_largest_value)
    {
        pb(b, a);  // Move elements greater than the average to 'b'
    }
    else if (current_value < third_largest_value)
    {
        pb(b, a);  // Move elements smaller than or equal to the average to 'b'
        rb(b);    // Reverse rotate 'b' to push smaller elements to the bottom
    }
    else
    	ra(a);
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


/*void	phase_two(t_stack_node **a, t_stack_node **b)
{
	while (*b)
	{
		set_positions(*a, *b);
		set_target_node_for_b(*a, *b);
		do_best_move(a, b);
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

void	set_target_node_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*current_a;
	t_stack_node	*target;
	int				best_match_index;

	current_b = b;
	while (current_b)
	{
		best_match_index = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > current_b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next_node;
		}
		if (best_match_index == INT_MAX)
			current_b->target_node = find_min_node(a);
		else
			current_b->target_node = target;
		current_b = current_b->next_node;
	}
}

int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}


int	cost_optimizer(t_stack_node *a, t_stack_node *b, t_stack_node *node)
{
	int	size_a;
	int	size_b;
	int	raw_cost;
	int	rr_cost;
	int	rrr_cost;

	size_a = stack_len(a);
	size_b = stack_len(b);
	rr_cost = ft_max_int(node->, node->target_node->position);
	rrr_cost = ft_max_int((size_a - node->position) % \
	size_a, (size_b - node->target_node->position) % size_b);
	raw_cost = ft_min_int(size_a - node->position, node->position) \
	+ ft_min_int(size_b - node->target_node->position, node->target_node->position);
	if (rr_cost < rrr_cost && rr_cost < raw_cost)
		return (cost_rr(node));
	else if (rrr_cost < rr_cost && rrr_cost < raw_cost)
		return (cost_rrr(a, b, node));
	else if (raw_cost <= rr_cost && raw_cost <= rrr_cost)
		return (cost_raw(a,b, node));
}

#define HOLD    0
#define RA      1  // Rotate A
#define RB      2  // Rotate B
#define RRA     3  // Reverse Rotate A
#define RRB     4  // Reverse Rotate B

int cost_raw(t_stack_node *a, t_stack_node *b, t_stack_node *node)
{
    int size_a = stack_len(a);  // Total size of stack a
    int size_b = stack_len(b);  // Total size of stack b
    
    if (!node)
        return (0);
    
    // Calculate cost for stack A
    if (node->position == 0) {
        node->move_a = HOLD;
    } else if (node->position <= size_a / 2) {
        node->move_a = RA;  // Rotate A
        node->cost_a = node->position;
    } else {
        node->move_a = RRA; // Reverse Rotate A
        node->cost_a = size_a - node->position;
    }

    // Calculate cost for stack B
    if (node->target_node->position == 0) {
        node->move_b = HOLD;
    } else if (node->target_node->position <= size_b / 2) {
        node->move_b = RB;  // Rotate B
        node->cost_b = node->target_node->position;
    } else {
        node->move_b = RRB;  // Reverse Rotate B
        node->cost_b = size_b - node->target_node->position;
    }

    return (1);
}
int cost_rr(t_stack_node *a, t_stack_node *b, t_stack_node *node)
{
    int size_a = stack_len(a);
    int size_b = stack_len(b);
    
    if (!node)
        return (0);
    
    // Calculate rotation for stack A
    if (node->position == 0) {
        node->move_a = HOLD;
    } else {
        node->move_a = RA;  // Rotate A
        node->cost_a = node->position;
    }

    // Calculate rotation for stack B
    if (node->target_node->position == 0) {
        node->move_b = HOLD;
    } else {
        node->move_b = RB;  // Rotate B
        node->cost_b = node->target_node->position;
    }

    return (1);
}

int cost_rrr(t_stack_node *a, t_stack_node *b, t_stack_node *node)
{
    int size_a = stack_len(a);
    int size_b = stack_len(b);
    
    if (!node)
        return (0);

    // Calculate reverse rotation for stack A
    if (node->position == 0) {
        node->move_a = HOLD;
    } else {
        node->move_a = RRA;  // Reverse Rotate A
        node->cost_a = size_a - node->position;
    }

    // Calculate reverse rotation for stack B
    if (node->target_node->position == 0) {
        node->move_b = HOLD;
    } else {
        node->move_b = RRB;  // Reverse Rotate B
        node->cost_b = size_b - node->target_node->position;
    }

    return (1);
}

int cost_to_pa(t_stack_node *a, t_stack_node *node)
{
    int cost = 0;
    t_stack_node *cur = a;
    
    if (!a || !node)
        return (0);
    
    // If node's value is greater than the max in a or less than the min in a
    if (node->value > find_max_value(a) || node->value < find_min_value(a))
    {
        // Move from top to bottom of the stack
        while (cur->next_node && cur->value < node->value && cost++ < stack_len(a))
            cur = cur->next_node;
        
        // Calculate the rotation cost for stack a
        if (cost <= stack_len(a) / 2)
        {
            node->move_a = RA;  // Rotate A
            node->cost_a = cost; // Number of rotations
        }
        else
        {
            node->move_a = RRA; // Reverse Rotate A
            node->cost_a = stack_len(a) - cost; // Reverse number of rotations
        }
    }
    else
    {
        // Move from bottom to top of the stack
        while (cur && cur->value != find_min_value(a) && cost++ < stack_len(a))
            cur = cur->next_node;
        
        while (cur && cur->value < node->value && cur->next_node && cur->next_node->value < node->value && cost++ < stack_len(a))
            cur = cur->next_node;
        
        // Calculate the rotation cost for stack a
        if (cost <= stack_len(a) / 2)
        {
            node->move_a = RA;  // Rotate A
            node->cost_a = cost; // Number of rotations
        }
        else
        {
            node->move_a = RRA; // Reverse Rotate A
            node->cost_a = stack_len(a) - cost; // Reverse number of rotations
        }
    }

    return (1);
}

int find_min_value(t_stack_node *a)
{
    int min_value = INT_MAX;
    t_stack_node *current = a;
    
    while (current)
    {
        if (current->value < min_value)
            min_value = current->value;
        current = current->next_node;
    }
    
    return min_value;
}

int find_max_value(t_stack_node *a)
{
    int max_value = INT_MIN;
    t_stack_node *current = a;
    
    while (current)
    {
        if (current->value > max_value)
            max_value = current->value;
        current = current->next_node;
    }
    
    return max_value;
}

void	do_best_move(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*current;
	t_stack_node	*best_node;
	int				best_cost;
	int				current_cost;
	int				size_a;
	int				size_b;

	current = *b;
	best_node = NULL;
	best_cost = INT_MAX;
	size_a = stack_len(*a);
	size_b = stack_len(*b);
	while (current)
	{
		current_cost = cost_optimizer(*a, *b, current);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_node = current;
		}
		current = current->next_node;
	}
	if (best_node)
	{
		execute_moves(a, b, best_node, size_a, size_b);
		pa(a, b);
	}
}

void	phase_three(t_stack_node **a, int size)
{
	int	min_pos;
	
	min_pos = get_position(*a, 0);
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
}*/
