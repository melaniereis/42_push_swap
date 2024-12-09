/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:12:47 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/09 16:46:18 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the maximum of two integers.
*/
int	ft_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
** Finds the minimum value among four integers.
*/
int	ft_find_min_cost(int a, int b, int c, int d)
{
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
