/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:44:16 by advorace          #+#    #+#             */
/*   Updated: 2025/09/14 11:41:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 -1)

#include "libft.h"
#include "ft_printf.h"
#include "stdio.h"

int	ft_atoi_safe(const char *nptr, int *out);
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
} t_stack;

t_stack	*stack_new(int num);
void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
void	stack_free(t_stack *lst);
int		stack_len(t_stack *lst);
int		error(t_stack **stack_a, t_stack **stack_b);
int		init_stack_a(t_stack **stack_a, int argc, char **argv);
void	swap(t_stack **stack);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	print_stack(t_stack **stack, char *stack_name);
t_stack	*stack_second_last(t_stack *lst);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

#endif
