/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:50:01 by advorace          #+#    #+#             */
/*   Updated: 2025/09/16 17:00:04 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	//printf("argument count: %d\n", argc);
	//printf("%s\n", argv[1]);
	if (!init_stack_a(&stack_a, argc, argv))
		return (error(&stack_a, &stack_b));
	//print_stack(&stack_a, "A");
	//print_stack(&stack_b, "B");
	main_sort(&stack_a, &stack_b, argc);
	//print_stack(&stack_a, "A");
	//print_stack(&stack_b, "B");
	stack_free(stack_a);
	stack_free(stack_b);
	return (0);
}
