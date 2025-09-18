/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_pa_pb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:29:04 by advorace          #+#    #+#             */
/*   Updated: 2025/09/18 16:04:06 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push elemnt from src to the top of dest
void push(t_stack **src, t_stack **dest)
{
	t_stack *temp;

	if (!*src)
		return ;
	temp = *src;
	*src = temp->next;
	temp->next = *dest;
	*dest = temp;
}
void pa(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
