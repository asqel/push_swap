/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:41:50 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:18:10 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = parse_args(argc, argv);
	stack_b = stack_new(stack_a->len);
	if (NULL == stack_b)
	{
		stack_free(stack_a);
		write_error_exit("Error\n", 1);
	}
	if (!stack_is_sorted(stack_a))
		stack_sort(stack_a, stack_b);
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
