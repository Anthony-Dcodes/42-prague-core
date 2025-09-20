/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:49:51 by advorace          #+#    #+#             */
/*   Updated: 2025/09/20 18:35:51 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
    int first_n, second_n, last_n;
    int max_rank = argc - 2; // 0-based max rank

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
	// Rotate and swap stack_b till sorted
	while (!check_sort_order(*stack_b, "descending"))
	{
		print_stack(stack_a, "A");
		print_stack(stack_b, "B");
		// ++counter;
		// if (counter == 6)
		// 	return ;
		//print_stack(stack_a, "A");
		//print_stack(stack_b, "B");
		if (first(*stack_b, &first_n) && second(*stack_b, &second_n) && last(*stack_b, &last_n))
		{
			// if (second_n > first_n)
			// {
			// 	sb(stack_b);
			// 	continue;
			// }
			if (second_n < first_n)
			{
				sb(stack_b);
				rb(stack_b);
				if (check_sort_order(*stack_b, "descending"))
					break;
				rb(stack_b);
				continue;
			}
			rb(stack_b);

		}
		print_stack(stack_a, "A");
		print_stack(stack_b, "B");
	}
	while (!check_sorted(*stack_a, *stack_b))
	{
		return;
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
		print_stack(stack_a, "A");
		print_stack(stack_b, "B");
		// break;
		// ++counter;
		// if (max_rank*10 < counter)
		// 	break;
	}
	//print_stack(stack_a, "A");
	//print_stack(stack_b, "B");
}

