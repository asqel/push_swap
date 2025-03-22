/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:22:02 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:37:22 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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

void	stack_rotate_up(t_stack *a)
{
	int	i;
	int	last;

	if (a->len < 2)
		return ;
	last = a->val[a->len - 1];
	i = a->len - 1;
	while (i > 0)
	{
		a->val[i] = a->val[i - 1];
		i--;
	}
	a->val[0] = last;
}

void	stack_rotate_down(t_stack *a)
{
	int	i;
	int	first;

	if (a->len < 2)
		return ;
	first = a->val[0];
	i = 0;
	while (i < a->len - 1)
	{
		a->val[i] = a->val[i + 1];
		i++;
	}
	a->val[a->len - 1] = first;
}
