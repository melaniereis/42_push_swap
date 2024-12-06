/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:12:47 by meferraz          #+#    #+#             */
/*   Updated: 2024/12/06 13:13:47 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

