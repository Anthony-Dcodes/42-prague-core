/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rra_rrb_rrr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 11:02:51 by advorace          #+#    #+#             */
/*   Updated: 2025/09/14 11:41:19 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
	t_stack *second_last;
	t_stack *last;

	if (!*stack || !(*stack)->next)
		return ;
	second_last = stack_second_last(*stack);
	last = stack_last(*stack);
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
void rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
