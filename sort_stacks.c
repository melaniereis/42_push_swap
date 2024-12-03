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
void phase_two(t_stack_node **a, t_stack_node **b);
void phase_three(t_stack_node **a, int size);
int get_position(t_stack_node *stack, int index);
int get_target_position(int index, t_stack_node *stack);
void rotate_both(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b);
void reverse_rotate_both(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b);
void do_move(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b);
int	abs_val(int n);
int	get_third_largest_value(t_stack_node *a);

void	sort_stacks(t_stack_node **a, t_stack_node **b, int size)
{
	//t_stack_node *current;
	//t_stack_node	*current_b;
	set_indices(a);
	phase_one(a, b, size);
	t_stack_node *current = *a;
    	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	t_stack_node *current_b = *b;
    	while (current_b)
	{
		printf("%d\n", current_b -> value);
		current_b = current_b -> next_node;
	}
	printf("--------------------\n");
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
	phase_two(a, b);
	current = *a;
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


void	phase_two(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;
	int	cost_a;
	int cost_b;
	int cheapest_cost;
	int cheapest_cost_a;
	int cheapest_cost_b;

	while (*b)
	{
		cheapest_cost = INT_MAX;
		tmp = *b;
		while (tmp)
		{
			cost_b = get_position(*b, tmp -> index);
			cost_a = get_target_position (tmp -> index, *a);
			if (abs_val(cost_a) + abs_val(cost_b) < cheapest_cost)
			{
				cheapest_cost = abs_val(cost_a) + abs_val(cost_b);
				cheapest_cost_a = cost_a;
				cheapest_cost_b = cost_b;
			}
			tmp = tmp -> next_node;
		}
		do_move(a, b, cheapest_cost_a, cheapest_cost_b);
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

int	abs_val(int n)
{
	return (n * (n >= 0) + (-n) * (n < 0));
}

int get_position(t_stack_node *stack, int index)
{
    int position;
    t_stack_node *current;

    position = 0;
    current = stack;
    while (current != NULL)
    {
        if (current->index == index)
            return (position);
        current = current->next_node;
        position++;
    }
    return (-1);
}

int	get_target_position(int index, t_stack_node *stack)
{
	int	target_pos;
	int min_index;
	int min_pos;

	target_pos = 0;
	min_index = INT_MAX;
	min_pos = 0;
	while (stack)
	{
		if (stack -> index > index && stack -> index < min_index)
		{
			min_index = stack->index;
			min_pos = target_pos;
		}
		if (stack -> index < min_index)
		{
			min_index = stack -> index;
			min_pos = target_pos;
		}
		target_pos++;
		stack = stack -> next_node;
	}
	if (min_index == INT_MAX)
		return (min_pos);
	return (target_pos);
}

void	do_move(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		reverse_rotate_both(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a,b);
}

void rotate_both(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b)
{
    while (*cost_a > 0 && *cost_b > 0)
    {
        rr(a, b);
        (*cost_a)--;
        (*cost_b)--;
    }
}

void reverse_rotate_both(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
    {
        rrr(a, b);
        (*cost_a)++;
        (*cost_b)++;
    }
}
