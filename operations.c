/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:32:22 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:38:01 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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
