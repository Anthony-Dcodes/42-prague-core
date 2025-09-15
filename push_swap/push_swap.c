/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:50:01 by advorace          #+#    #+#             */
/*   Updated: 2025/09/15 19:48:37 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int		out;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(&stack_a, argc, argv))
		return (error(&stack_a, &stack_b));
	print_stack(&stack_a, "a");

	sa(&stack_a);
	print_stack(&stack_a, "a");

	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	rotate(&stack_a);
	print_stack(&stack_a, "a");
	print_stack(&stack_b, "b");
	rrr(&stack_a, &stack_b);
	print_stack(&stack_a, "a");
	print_stack(&stack_b, "b");
	if (first(stack_a, &out))
		printf("first stack a value: %d\n", out);
	if (second(stack_a, &out))
		printf("second stack a value: %d\n", out);
	if (last(stack_a, &out))
		printf("last stack a value: %d\n", out);

	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
