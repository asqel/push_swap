/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:19:52 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/06 00:15:15 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

void	write_error(char *err)
{
	int	len;

	len = 0;
	while ('\0' != err[len])
		len++;
	write(STDERR_FILENO, err, len);
}


void	write_error_exit(char *err, int exit_code)
{
	int	len;

	len = 0;
	while ('\0' != err[len])
		len++;
	write(STDERR_FILENO, err, len);
	exit(exit_code);
}

