/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 19:49:51 by advorace          #+#    #+#             */
/*   Updated: 2025/09/16 16:59:09 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void main_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	first_n;
	int	second_n;
	int number_cnt;

	number_cnt = argc - 2;
	while (!check_sorted(*stack_a, *stack_b))
	{
		if (first(*stack_a, &first_n))
		{
			// If max number is first put it at the end
			if (first_n == number_cnt && (*stack_a)->next)
				ra(stack_a);
			else if ((*stack_a)->next)
			{
				pb(stack_a, stack_b);
				if (first(*stack_b, &first_n))
				{
					if (second(*stack_b, &second_n))
					{
						if (first_n < second_n)
							sb(stack_b);
					}
				}
			}
			else if (check_sort_order(*stack_a, "ascending")
					&& check_sort_order(*stack_b, "descending"))
			{
				while(*stack_b)
					pa(stack_a, stack_b);
			}
		}
	}
	return ;
}
