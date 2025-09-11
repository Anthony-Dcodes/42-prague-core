/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:50:01 by advorace          #+#    #+#             */
/*   Updated: 2025/09/11 21:37:41 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack	*temp;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(&stack_a, argc, argv))
		return (error(&stack_a, &stack_b));
	temp = stack_a;
	ft_printf("Stack len: %d\n", stack_len(stack_a));
	while (temp)
	{
		ft_printf("%d\n", temp->value);
		temp = temp->next;
	}
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
