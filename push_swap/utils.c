/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:55:22 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 21:31:18 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a || *stack_a)
	{
		stack_free(*stack_a);
		*stack_a = NULL;
	}
	if (stack_b || *stack_b)
	{
		stack_free(*stack_b);
		*stack_b = NULL;
	}
	write(2, "Error\n", 6);
	return (0);
}

// Validate that input
// Every value has to be valid int
int	ft_atoi_safe(const char *nptr, int *out)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
	}
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (0);
		if (sign == 1 && result > (INT_MAX - (nptr[i] - '0')) / 10)
			return (0);
		if (sign == -1 && - result < (INT_MIN + (nptr[i] - '0')) / 10)
			return (0);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	*out = (int)(sign * result);
	return (1);
}
