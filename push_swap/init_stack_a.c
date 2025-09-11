/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:50:04 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 21:43:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int	i;
	int	value;
	t_stack *new_node;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &value))
			return (0);
		new_node = stack_new(value);
		if (!new_node)
			return (0);
		stack_add_back(stack_a, new_node);
		++i;
	}
	return (1);
}
