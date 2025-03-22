/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 01:09:19 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 14:54:38 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

#define printf(x, ...)

void print_stack(t_stack *a)
{
	printf("TOP -> BOTTOM\n");
	for (int i =a->len - 1; i >= 0; i--)
	{
		printf("%d ", a->val[i]);
	}
	printf("\n");
}

void	sort_3(t_stack *a, t_stack *b)
{
	if (a->len == 2 && a->val[0] < a->val[1])
		return (stack_op_sa(a));
	if (a->len == 2)
		return ;
	if (a->val[0] > a->val[2] && a->val[2] > a->val[1])
		return (stack_op_sa(a));
	if (a->val[2] > a->val[1] && a->val[1] > a->val[0])
		return (stack_op_sa(a), stack_op_rra(a));
	if (a->val[2] > a->val[0] && a->val[0] > a->val[1])
		return (stack_op_ra(a));
	if (a->val[1] > a->val[0] && a->val[0] > a->val[2])
		return (stack_op_sa(a), stack_op_ra(a));
	if (a->val[1] > a->val[2] && a->val[2] > a->val[0])
		return (stack_op_rra(a));
}

int	stack_get_min_idx(t_stack *a)
{
	int min_idx;
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
	int max_idx;
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

void	sort_5(t_stack *a, t_stack *b)
{
	while (stack_get_min_idx(a) != a->len - 1)
	{
		if (stack_get_min_idx(a) < a->len / 2)
			stack_op_rra(a);
		else
			stack_op_ra(a);
	}
	stack_op_pb(a, b);
	while (stack_get_min_idx(a) != a->len - 1)
	{
		if (stack_get_min_idx(a) < a->len / 2)
			stack_op_rra(a);
		else
			stack_op_ra(a);
	}
	stack_op_pb(a, b);
	sort_3(a, b);
	stack_op_pa(a, b);
	stack_op_pa(a, b);
}

void big_sort(t_stack *a, t_stack *b);

void stack_sort(t_stack *a, t_stack *b)
{
	print_stack(a);
	if (a->len <= 3)
		return sort_3(a, b);
	if (a->len <= 5)
		return sort_5(a, b);
	big_sort(a, b);
	print_stack(a);
}

int	get_max_cost(t_stack *a, int num)
{
	int	max_idx;

	max_idx = stack_get_max_idx(a);
	if (max_idx > a->len / 2)
		return a->len - max_idx - 1;
	else
		return max_idx;
}

int	get_min_cost(t_stack *a, int num)
{
	int	min_idx;

	min_idx = stack_get_min_idx(a) + 1;
	if (min_idx > a->len / 2)
		return a->len - min_idx - 1;
	else
		return min_idx;
}

int	get_insert_cost(t_stack *a, int num)
{
	int	cur;
	int	before;

	if (a->val[a->len - 1] > num && num > a->val[0])
		return (0);
	if (a->val[stack_get_max_idx(a)] < num)
		return get_max_cost(a, num);
	if (a->val[stack_get_min_idx(a)] > num)
		return get_min_cost(a, num);
	cur = 0;
	while (cur < a->len)
	{
		if (cur == 0)
			before = a->val[a->len - 1];
		else
			before = a->val[cur - 1];
		if (before > num && num > a->val[cur])
		{
			if (cur > a->len / 2)
				return a->len - cur - 1;
			else
				return cur;
		}
		cur++;
	}
	return (-1);
}

int	get_who_insert(t_stack *a, t_stack *b)
{
	int	who_cost;
	int who_pos;
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

void	get_a_rotation(t_stack *a, int num, int rot[4])
{
	int	cur;
	int	before;
	int	max_idx;

	if (a->val[a->len - 1] > num && num > a->val[0])
	{
		rot[0] = 0;
		rot[2] = 0;
		return ;
	}
	if (a->val[stack_get_max_idx(a)] < num)
	{
		max_idx = stack_get_max_idx(a);
		if (max_idx > a->len / 2)
			rot[0] = a->len - max_idx;
		else
			rot[0] = max_idx;
		rot[2] = max_idx <= a->len / 2;
		return ;
	}
	if (a->val[stack_get_min_idx(a)] > num)
	{
		max_idx = stack_get_min_idx(a) + 1;
		if (max_idx > a->len / 2)
			rot[0] = a->len - max_idx;
		else
			rot[0] = max_idx;
		rot[2] = max_idx <= a->len / 2;
		return ;
	}

	cur = 0;
	while (cur < a->len)
	{
		if (cur == 0)
			before = a->val[a->len - 1];
		else
			before = a->val[cur - 1];
		if (before > num && num > a->val[cur])
		{

			if (cur > a->len / 2)
				rot[0] = a->len - cur;
			else
				rot[0] = cur;
			//printf("cur %d\n", cur);
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

void	rotate_both_up(t_stack *a, t_stack *b, int rot[4])
{
	while (rot[0] > 0 && rot[1] > 0)
	{
		stack_op_rr(a, b);
		rot[0]--;
		rot[1]--;
	}
	while (rot[0] > 0)
	{
		stack_op_ra(a);
		rot[0]--;
	}
	while (rot[1] > 0)
	{
		stack_op_rb(b);
		rot[1]--;
	}
}

void	rotate_both_down(t_stack *a, t_stack *b, int rot[4])
{
	while (rot[0] > 0 && rot[1] > 0)
	{
		stack_op_rrr(a, b);
		rot[0]--;
		rot[1]--;
	}
	while (rot[0] > 0)
	{
		stack_op_rra(a);
		rot[0]--;
	}
	while (rot[1] > 0)
	{
		stack_op_rrb(b);
		rot[1]--;
	}
}

void	rotate_a_up_b_down(t_stack *a, t_stack *b, int rot[4])
{
	while (rot[0] > 0 && rot[1] > 0)
	{
		stack_op_ra(a);
		stack_op_rrb(b);
		rot[0]--;
		rot[1]--;
	}
	while (rot[0] > 0)
	{
		stack_op_ra(a);
		rot[0]--;
	}
	while (rot[1] > 0)
	{
		stack_op_rrb(b);
		rot[1]--;
	}
}

void	rotate_a_down_b_up(t_stack *a, t_stack *b, int rot[4])
{
	while (rot[0] > 0 && rot[1] > 0)
	{
		stack_op_rra(a);
		stack_op_rb(b);
		rot[0]--;
		rot[1]--;
	}
	while (rot[0] > 0)
	{
		stack_op_rra(a);
		rot[0]--;
	}
	while (rot[1] > 0)
	{
		stack_op_rb(b);
		rot[1]--;
	}
}

void	smart_rotate(t_stack *a, t_stack *b, int pos)
{
	int	rot[4]; // 0: num a, 1: num b, 3: a_dir, 4: b_dir, 0 up

	rot[0] = 0;
	rot[1] = 0;
	rot[2] = 0;
	rot[3] = 0;
	get_rotations(a, b, pos, rot);
	//printf("les rot %d %d %d %d\n", rot[0], rot[1], rot[2], rot[3]);
	if (rot[2] == 0 && rot[3] == 0)
		return rotate_both_up(a, b, rot);
	if (rot[2] == 1 && rot[3] == 1)
		return rotate_both_down(a, b, rot);
	if (rot[2] == 0 && rot[3] == 1)
		return rotate_a_up_b_down(a, b, rot);
	if (rot[2] == 1 && rot[3] == 0)
		return rotate_a_down_b_up(a, b, rot);
}

void	rotate_to_min(t_stack *a)
{
	int	min_idx;
	int	min;
	int	i;

	min_idx = 0;
	i = 0;
	while (i < a->len)
	{
		if (a->val[i] < a->val[min_idx])
			min_idx = i;
		i++;
	}
	min = a->val[min_idx];
	if (min_idx > a->len / 2)
		while (a->val[a->len - 1] != min)
			stack_op_ra(a);
	else
		while (a->val[a->len - 1] != min)
			stack_op_rra(a);
}

void big_sort(t_stack *a, t_stack *b)
{
	int	who_to_insert_pos;
	int	where_to_insert;

	while (a->len > 3)
		stack_op_pb(a, b);
	sort_3(a, b);
	while (b->len > 0)
	{
		//printf("STack\n");
		who_to_insert_pos = get_who_insert(a, b);
		//printf("INSERING %d\n", b->val[who_to_insert_pos]);
		smart_rotate(a, b, who_to_insert_pos);
		stack_op_pa(a, b);
	}
	//printf("STack\n");
	rotate_to_min(a);

	//who_to_insert_pos = get_who_insert(a, b);
	//printf("WHO TO INSERT: %d:%d\n", who_to_insert_pos, b->val[who_to_insert_pos]);
	//printf("Where TO INSERT: %d\n", get_where_insert(a, b->val[who_to_insert_pos]));
	//printf("stack_b\n");
	//print_stack(b);

}