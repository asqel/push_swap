/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:08:20 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/18 17:14:05 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


// [bottom, ..., top]
typedef struct s_stack
{
	int	len;
	int	*val;
	int alloc_len;
}	t_stack;

t_stack	*parse_args(int argc, char **argv);

void	write_error(char *err);
void	write_error_exit(char *err, int exit_code);\
int		ft_atoi(char *text, int *res);

t_stack	*stack_new(int size);
void	stack_free(t_stack *s);
void	stack_push_from(t_stack *a, t_stack *b);

int	stack_contain(t_stack *s, int v);
int stack_is_sorted(t_stack *s);


void	stack_rotate_up(t_stack *a);
void	stack_rotate_down(t_stack *a);

void	stack_op_sa(t_stack *s);
void	stack_op_sb(t_stack *s);
void	stack_op_ss(t_stack *a, t_stack *b);
void	stack_op_pa(t_stack *a, t_stack *b);
void	stack_op_pb(t_stack *a, t_stack *b);
void	stack_op_ra(t_stack *a);
void	stack_op_rb(t_stack *b);
void	stack_op_rr(t_stack *a, t_stack *b);
void	stack_op_rra(t_stack *a);
void	stack_op_rrb(t_stack *b);
void	stack_op_rrr(t_stack *a, t_stack *b);

#endif