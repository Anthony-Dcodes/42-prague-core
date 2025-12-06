/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:55:22 by advorace          #+#    #+#             */
/*   Updated: 2025/12/06 12:16:08 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
	{
		stack_free(*stack_a);
		*stack_a = NULL;
	}
	if (stack_b && *stack_b)
	{
		stack_free(*stack_b);
		*stack_b = NULL;
	}
	write(2, "Error\n", 6);
	return (0);
}

void	print_stack(t_stack **stack, char *stack_name)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	ft_printf("Stack: %s\n", stack_name);
	i = 0;
	while (temp)
	{
		ft_printf("%d: %d\n", i, temp->value);
		temp = temp->next;
		++i;
	}
}
