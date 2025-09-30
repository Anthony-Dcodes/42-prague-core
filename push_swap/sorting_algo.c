/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:49:51 by advorace          #+#    #+#             */
/*   Updated: 2025/09/30 20:46:36 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
    int first_n, first_n_a, first_n_b, last_n;
    int max_rank = argc - 2; // 0-based max rank
	//last_n = 0;

	// Populate stack_b till there is only max value in stack_a
    while (!check_sorted(*stack_a, *stack_b))
    {
		// print_stack(stack_a, "A");
		// print_stack(stack_b, "B");
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
        }
		if (!(*stack_a)->next)
			break;
    }
	while (!check_sorted(*stack_a, *stack_b))
	{
		if (first(*stack_b, &first_n_b) && first(*stack_a, &first_n_a) && last(*stack_b, &last_n))
		{
			if (first_n_a - 1 == first_n_b)
				pa(stack_b, stack_a);
			else if (stack_number_pos(*stack_b, first_n_a - 1) <= (stack_len(*stack_b) / 2))
				rb(stack_b);
			else
				rrb(stack_b);
		}
		//print_stack(stack_a, "A");
		//print_stack(stack_b, "B");
		// break;
		// ++counter;
		// if (max_rank*10 < counter)
		// 	break;
	}
	//print_stack(stack_a, "A");
	//print_stack(stack_b, "B");
}

