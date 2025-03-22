/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:03:11 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:41:52 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_get_min_idx(t_stack *a)
{
	int	min_idx;
	int	i;

	i = 0;
	min_idx = 0;
	while (i < a->len)
	{
		if (a->val[i] < a->val[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

int	stack_get_max_idx(t_stack *a)
{
	int	max_idx;
	int	i;

	i = 0;
	max_idx = 0;
	while (i < a->len)
	{
		if (a->val[i] > a->val[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

int	get_max_cost(t_stack *a)
{
	int	max_idx;

	max_idx = stack_get_max_idx(a);
	if (max_idx > a->len / 2)
		return (a->len - max_idx - 1);
	return (max_idx);
}

int	get_min_cost(t_stack *a)
{
	int	min_idx;

	min_idx = stack_get_min_idx(a) + 1;
	if (min_idx > a->len / 2)
		return (a->len - min_idx - 1);
	return (min_idx);
}
