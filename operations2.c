/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:20:00 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:37:14 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	stack_op_sa(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = s->val[s->len - 1];
	s->val[s->len - 1] = s->val[s->len - 2];
	s->val[s->len - 2] = tmp;
	write(1, "sa\n", 3);
}

void	stack_op_sb(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = s->val[s->len - 1];
	s->val[s->len - 1] = s->val[s->len - 2];
	s->val[s->len - 2] = tmp;
	write(1, "sb\n", 3);
}

void	stack_op_ss(t_stack *a, t_stack *b)
{
	int	tmp;

	write(1, "ss\n", 3);
	if (a->len >= 2)
	{
		tmp = a->val[a->len - 1];
		a->val[a->len - 1] = a->val[a->len - 2];
		a->val[a->len - 2] = tmp;
	}
	if (b->len >= 2)
	{
		tmp = b->val[b->len - 1];
		b->val[b->len - 1] = b->val[b->len - 2];
		b->val[b->len - 2] = tmp;
	}
}

void	stack_op_pa(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
	a->val[a->len] = b->val[b->len - 1];
	b->len--;
	a->len++;
	write(1, "pa\n", 3);
}

void	stack_op_pb(t_stack *a, t_stack *b)
{
	if (a->len == 0)
		return ;
	b->val[b->len] = a->val[a->len - 1];
	a->len--;
	b->len++;
	write(1, "pb\n", 3);
}
