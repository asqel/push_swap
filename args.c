/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:10:26 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/18 17:29:27 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*parse_args(int argc, char **argv)
{
	int		i;
	t_stack	*res;
	int		err;
	int		tmp;

	if (2 == argc && 0 != ft_atoi(argv[1], &tmp))
		(write_error("Error\n"), exit(1));
	else if (2 == argc)
		exit(0);
	res = stack_new(argc - 1);
	i = argc - 1;
	while (i >= 1)
	{
		tmp = 0;
		err = ft_atoi(argv[i], &tmp);
		if (err || stack_contain(res, tmp))
		{
			stack_free(res);
			write_error_exit("Error\n", 1);
		}
		res->val[res->len] = tmp;
		res->len++;
		i--;
	}
	return (res);
}