/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:49:51 by advorace          #+#    #+#             */
/*   Updated: 2025/09/18 16:06:08 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
    int first_n, second_n;
    int max_rank = argc - 2; // 0-based max rank


    while (!check_sorted(*stack_a, *stack_b))
    {
		//print_stack(stack_a, "A");
		//print_stack(stack_b, "B");
        if (!first(*stack_a, &first_n))
            break; // empty stack, safety

        // If max rank is at the top, rotate to the end
        if (first_n == max_rank && (*stack_a)->next)
        {
            ra(stack_a);
            continue;
        }

        // Push smaller numbers to stack_b
        if ((*stack_a)->next)
        {
            pb(stack_a, stack_b);

            // Ensure descending order in stack_b
            if (first(*stack_b, &first_n) && second(*stack_b, &second_n))
            {
                if (first_n < second_n)
                    sb(stack_b);
            }
            continue;
        }
		if (!(*stack_a)->next)
			break;
    }
	while (!check_sorted(*stack_a, *stack_b))
	{
		// Ensure descending order in stack_b
		if (first(*stack_b, &first_n) && second(*stack_b, &second_n))
		{
			if (first_n < second_n)
			{
				sb(stack_b);
				continue;
			}
		}
		if (first(*stack_b, &first_n))
			pa(stack_b, stack_a);
		//print_stack(stack_a, "A");
		//print_stack(stack_b, "B");
	}
}

