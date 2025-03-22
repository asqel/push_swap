/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlleres <axlleres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:08:20 by axlleres          #+#    #+#             */
/*   Updated: 2025/03/22 21:48:06 by axlleres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// [bottom, ..., top]
typedef struct s_stack
{
	int	len;
	int	*val;
	int	alloc_len;
}	t_stack;

t_stack	*parse_args(int argc, char **argv);

void	write_error(char *err);
void	write_error_exit(char *err, int exit_code);
int		ft_atoi(char *text, int *res);

t_stack	*stack_new(int size);
void	stack_free(t_stack *s);
void	stack_push_from(t_stack *a, t_stack *b);

int		stack_contain(t_stack *s, int v);
int		stack_is_sorted(t_stack *s);

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

int		stack_get_min_idx(t_stack *a);
int		stack_get_max_idx(t_stack *a);
int		get_max_cost(t_stack *a);
int		get_min_cost(t_stack *a);

void	stack_sort(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);
void	big_sort(t_stack *a, t_stack *b);
void	get_max_rotation(t_stack *a, int rot[4]);
void	get_min_rotation(t_stack *a, int rot[4]);

void	rotate_both_up(t_stack *a, t_stack *b, int rot[4]);
void	rotate_both_down(t_stack *a, t_stack *b, int rot[4]);
void	rotate_a_up_b_down(t_stack *a, t_stack *b, int rot[4]);
void	rotate_a_down_b_up(t_stack *a, t_stack *b, int rot[4]);
void	rotate_to_min(t_stack *a);
int		get_who_insert(t_stack *a, t_stack *b);

#endif