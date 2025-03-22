/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:32:22 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/18 18:17:41 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_op_ra(t_stack *a)
{
	stack_rotate_up(a);
	write(1, "ra\n", 3);
}


void	stack_op_rb(t_stack *b)
{
	stack_rotate_up(b);
	write(1, "rb\n", 3);
}

void	stack_op_rr(t_stack *a, t_stack *b)
{
	stack_rotate_up(a);
	stack_rotate_up(b);
	write(1, "rr\n", 3);
}


void	stack_op_rra(t_stack *a)
{
	stack_rotate_down(a);
	write(1, "rra\n", 4);
}


void	stack_op_rrb(t_stack *b)
{
	stack_rotate_down(b);
	write(1, "rrb\n", 4);
}

void	stack_op_rrr(t_stack *a, t_stack *b)
{
	stack_rotate_down(a);
	stack_rotate_down(b);
	write(1, "rrr\n", 4);
}