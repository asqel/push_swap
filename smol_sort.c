/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smol_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:04:09 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:39:07 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
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
	sort_3(a);
	stack_op_pa(a, b);
	stack_op_pa(a, b);
}
