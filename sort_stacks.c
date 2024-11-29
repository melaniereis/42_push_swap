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
void phase_two(t_stack_node **a, t_stack_node **b);
void phase_three(t_stack_node **a, int size);
int get_position(t_stack_node *stack, int index);
int get_target_position(int index, t_stack_node *stack);
void rotate_both(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b);
void reverse_rotate_both(t_stack_node **a, t_stack_node **b, int *cost_a, int *cost_b);
void do_move(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b);
int	abs_val(int n);

void	sort_stacks(t_stack_node **a, t_stack_node **b, int size)
{
	t_stack_node *current;
	set_indices(a);
	phase_one(a, b, size);
	current = *a;
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");
	phase_two(a, b);
	/*current = *a;
	while (current)
	{
		printf("%d\n", current -> value);
		current = current -> next_node;
	}
	printf("--------------------\n");*/
	phase_three(a, size);
}

void	phase_one(t_stack_node **a, t_stack_node **b, int total_size)
{
	int	pushed;
	int two_thirds;

	while (total_size > 3 && !is_stack_sorted(*a))
	{
		pushed = 0;
		two_thirds = total_size / 3 * 2;
		while (pushed < two_thirds && !is_stack_sorted(*a))
		{
			if ((*a) -> index <= two_thirds)
			{
				pb(b, a);
				pushed++;
				total_size--;
				if ((*b) -> index <= total_size / 3)
					rb(b);
			}
			else
				ra(a);
		}
		pushed = 0;
	}
	if (total_size == 3 && !is_stack_sorted(*a))
		sort_three(a);
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

int	get_position(t_stack_node *stack, int index)
{
	int	pos;
	
	pos = 0;
	while (stack)
	{
		if (stack -> index == index)
			return (pos);
		pos++;
		stack = stack -> next_node;
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
