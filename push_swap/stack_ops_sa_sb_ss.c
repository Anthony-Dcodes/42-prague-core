/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_sa_sb_ss.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:54:06 by advorace          #+#    #+#             */
/*   Updated: 2025/09/15 19:23:28 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack
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

void sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
