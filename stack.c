/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:09:49 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/18 18:28:08 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_new(int size)
{
	t_stack	*res;

	res = malloc(sizeof(t_stack));
	if (NULL == res)
		return (res);
	res->len = 0;
	res->alloc_len = size;
	res->val = malloc(sizeof(int) * size);
	if (NULL == res->val)
		return (free(res), NULL);
	return (res);
}

void	stack_free(t_stack *s)
{
	free(s->val);
	free(s);
}

int	stack_contain(t_stack *s, int v)
{
	int	i;

	i = 0;
	while (i < s->len)
	{
		if (s->val[i] == v)
			return (1);
		i++;
	}
	return (0);
}

int stack_is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->len)
	{
		if (s->val[i - 1] < s->val[i])
			return (0);
		i++;
	}
	return (1);
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

void	stack_push_from(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->val[a->len - 1];
	a->len--;
	b->val[b->len] = tmp;
	b->len++;
}