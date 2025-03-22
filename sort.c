/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:09:19 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:47:40 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	stack_sort(t_stack *a, t_stack *b)
{
	if (a->len <= 3)
		return (sort_3(a));
	if (a->len <= 5)
		return (sort_5(a, b));
	big_sort(a, b);
}

void	get_a_rotation(t_stack *a, int num, int rot[4])
{
	int	cur;
	int	before;

	if (a->val[a->len - 1] > num && num > a->val[0])
		return ;
	if (a->val[stack_get_max_idx(a)] < num)
		return (get_max_rotation(a, rot));
	if (a->val[stack_get_min_idx(a)] > num)
		return (get_min_rotation(a, rot));
	cur = 0;
	while (cur < a->len)
	{
		before = a->val[cur - 1];
		if (cur == 0)
			before = a->val[a->len - 1];
		if (before > num && num > a->val[cur])
		{
			rot[0] = cur;
			if (cur > a->len / 2)
				rot[0] = a->len - cur;
			rot[2] = cur <= a->len / 2;
			return ;
		}
		cur++;
	}
}

void	get_rotations(t_stack *a, t_stack *b, int pos, int rot[4])
{
	rot[1] = b->len - pos - 1;
	rot[3] = pos < b->len / 2;
	if (pos < b->len / 2)
		rot[1] = pos + 1;
	get_a_rotation(a, b->val[pos], rot);
}

void	smart_rotate(t_stack *a, t_stack *b, int pos)
{
	int	rot[4];

	rot[0] = 0;
	rot[1] = 0;
	rot[2] = 0;
	rot[3] = 0;
	get_rotations(a, b, pos, rot);
	if (rot[2] == 0 && rot[3] == 0)
		return (rotate_both_up(a, b, rot));
	if (rot[2] == 1 && rot[3] == 1)
		return (rotate_both_down(a, b, rot));
	if (rot[2] == 0 && rot[3] == 1)
		return (rotate_a_up_b_down(a, b, rot));
	if (rot[2] == 1 && rot[3] == 0)
		return (rotate_a_down_b_up(a, b, rot));
}

void	big_sort(t_stack *a, t_stack *b)
{
	int	who_to_insert_pos;

	while (a->len > 3)
		stack_op_pb(a, b);
	sort_3(a);
	while (b->len > 0)
	{
		who_to_insert_pos = get_who_insert(a, b);
		smart_rotate(a, b, who_to_insert_pos);
		stack_op_pa(a, b);
	}
	rotate_to_min(a);
}
