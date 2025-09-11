/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_sa_sb_ss.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:54:06 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 22:22:05 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;

	if (!*stack_a || !(*stack_a)->next)
		return ;

	first = *stack_a;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack_a = second;
}
