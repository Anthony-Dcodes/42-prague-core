/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_sa_sb_ss.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:54:06 by advorace          #+#    #+#             */
/*   Updated: 2025/09/14 11:43:56 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!*stack || !(*stack)->next)
		return ;

	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}

void swap_a(t_stack **stack_a)
{
	swap(stack_a);
}

void swap_b(t_stack **stack_b)
{
	swap(stack_b);
}

void swap_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
