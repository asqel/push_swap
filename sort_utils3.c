/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:33:08 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:44:19 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_insert_cost(t_stack *a, int num)
{
	int	cur;
	int	before;

	if (a->val[a->len - 1] > num && num > a->val[0])
		return (0);
	if (a->val[stack_get_max_idx(a)] < num)
		return (get_max_cost(a));
	if (a->val[stack_get_min_idx(a)] > num)
		return (get_min_cost(a));
	cur = 0;
	while (cur < a->len)
	{
		before = a->val[cur - 1];
		if (cur == 0)
			before = a->val[a->len - 1];
		if (before > num && num > a->val[cur])
		{
			if (cur > a->len / 2)
				return (a->len - cur - 1);
			else
				return (cur);
		}
		cur++;
	}
	return (-1);
}

int	get_who_insert(t_stack *a, t_stack *b)
{
	int	who_cost;
	int	who_pos;
	int	current_cost;
	int	current;

	current = 0;
	who_cost = -1;
	while (current < b->len)
	{
		current_cost = get_insert_cost(a, b->val[current]);
		if (current < b->len / 2)
			current_cost += current + 1;
		else
			current_cost += (b->len - current);
		if (who_cost < 0 || current_cost < who_cost)
		{
			who_cost = current_cost;
			who_pos = current;
		}
		current++;
	}
	return (who_pos);
}

void	get_max_rotation(t_stack *a, int rot[4])
{
	int	max_idx;

	max_idx = stack_get_max_idx(a);
	if (max_idx > a->len / 2)
		rot[0] = a->len - max_idx;
	else
		rot[0] = max_idx;
	rot[2] = max_idx <= a->len / 2;
}

void	get_min_rotation(t_stack *a, int rot[4])
{
	int	max_idx;

	max_idx = stack_get_min_idx(a) + 1;
	if (max_idx > a->len / 2)
		rot[0] = a->len - max_idx;
	else
		rot[0] = max_idx;
	rot[2] = max_idx <= a->len / 2;
}
