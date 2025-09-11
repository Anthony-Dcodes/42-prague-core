/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:50:04 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 21:34:00 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &value))
			return (0);
		if (i == 1)
		{
			*stack_a = stack_new(value);
			if (!stack_a)
				return (0);
		}
		else
			stack_add_back(stack_a, stack_new(value));
		++i;
	}
	return (1);
}
