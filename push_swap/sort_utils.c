/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 23:41:13 by advorace          #+#    #+#             */
/*   Updated: 2025/11/29 23:41:54 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
		return (0);
	if (!stack_a)
		return (1);
	while (stack_a->next)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	sort_three(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_len(*stack_a) != 3)
		return ;
	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

int	find_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	int	min_pos;

	min = find_min(stack);
	pos = 0;
	min_pos = 0;
	while (stack)
	{
		if (stack->value == min)
		{
			min_pos = pos;
			break ;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

void	rotate_to_top(t_stack **stack, int pos, char stack_name)
{
	int	len;

	len = stack_len(*stack);
	if (pos <= len / 2)
	{
		while (pos-- > 0)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
	}
	else
	{
		while (pos++ < len)
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
	}
}
