/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:27:56 by advorace          #+#    #+#             */
/*   Updated: 2025/09/15 19:45:12 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first(t_stack *stack, int *out)
{
	if (!stack || !out)
		return (0);
	*out = stack->value;
	return (1);
}

int second(t_stack *stack, int *out)
{
	if (!stack || !stack->next || !out)
		return (0);
	*out = stack->next->value;
	return (1);
}

int last(t_stack *stack, int *out)
{
	if (!stack || !out)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	*out = stack->value;
	return (1);
}
