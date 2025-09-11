/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:55:22 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 18:15:26 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a || *stack_a)
	{
		stack_free(stack_a);
		*stack_a = NULL;
	}
	if (stack_b || *stack_b)
	{
		stack_free(stack_b);
		*stack_b = NULL;
	}
	write(2, "Error\n", 6);
	return (0);
}
