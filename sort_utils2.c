/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:32:25 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:46:49 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
