/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_pa_pb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:29:04 by advorace          #+#    #+#             */
/*   Updated: 2025/09/14 10:12:44 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_b;
	t_stack *second_b;

	if (!*stack_b)
		return ;
	first_b = *stack_b;
	second_b = first_b->next;

	first_b->next = *stack_a;
	*stack_a = first_b;
	*stack_b = second_b;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first_a;
	t_stack *second_a;

	if (!*stack_a)
		return ;
	first_a = *stack_a;
	second_a = first_a->next;

	first_a->next = *stack_b;
	*stack_b = first_a;
	*stack_a = second_a;
}
