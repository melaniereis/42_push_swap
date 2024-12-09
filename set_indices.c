/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indices.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:49:02 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 17:02:02 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_arr(int *arr, int size);
static int	find_index(int *arr, int size, int value);

/*
** Sets the index for each node in stack A based on their values.
*/
void	set_indices(t_stack_node **a)
{
	t_stack_node	*temp;
	int				*arr;
	int				size;
	int				i;

	size = stack_len(*a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	i = 0;
	temp = *a;
	while (temp)
	{
		arr[i++] = temp->value;
		temp = temp->next_node;
	}
	sort_arr(arr, size);
	temp = *a;
	while (temp)
	{
		temp->index = find_index(arr, size, temp->value);
		temp = temp->next_node;
	}
	free(arr);
}

/*
** Sorts an array of integers in ascending order using a simple 
** sorting algorithm.
*/
static void	sort_arr(int *arr, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				i = 0;
				break ;
			}
			j++;
		}
		if (j == size)
			i++;
	}
}

/*
** Finds the index of a given value in an array.
*/
static int	find_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
