/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_ra_rb_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 10:30:36 by advorace          #+#    #+#             */
/*   Updated: 2025/09/15 19:24:31 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift all elements of stack by 1
// First becomes last
void rotate(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = stack_last(*stack);
	last->next = first;
	*stack = first->next;
	first->next = NULL;
}

void ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	printf("rr\n");
}
