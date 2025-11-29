/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_sort_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:40:00 by advorace          #+#    #+#             */
/*   Updated: 2025/11/29 23:33:25 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_sorted(t_stack *stack_a, t_stack *stack_b)
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

static void	sort_three(t_stack **stack_a)
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

static int	find_min(t_stack *stack)
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

static int	find_min_pos(t_stack *stack)
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

static void	rotate_to_top(t_stack **stack, int pos, char stack_name)
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

static void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = stack_len(*stack_a);
	if (len == 2)
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
	}
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4 || len == 5)
	{
		while (len > 3)
		{
			rotate_to_top(stack_a, find_min_pos(*stack_a), 'a');
			pb(stack_a, stack_b);
			len--;
		}
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_b, stack_a);
	}
}

static int	find_max_pos(t_stack *stack)
{
	int		max;
	int		pos;
	int		max_pos;
	t_stack	*tmp;

	tmp = stack;
	max = tmp->value;
	pos = 0;
	max_pos = 0;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}
/*
Scans all elements of stack A exactly once
Pushes only the values inside the chunk range to stack B
Rotates A when a value isn't in the chunk
Optionally rotates B to keep smaller chunk values toward the bottom
→ This helps with faster sorting later.
*/
static void	push_chunk_to_b(t_stack **stack_a, t_stack **stack_b,
								int chunk_min, int chunk_max)
{
	int	len;
	int	rotations;

	len = stack_len(*stack_a);
	rotations = 0;
	while (rotations < len)
	{
		if ((*stack_a)->value >= chunk_min
			&& (*stack_a)->value <= chunk_max)
		{
			pb(stack_a, stack_b);
			if (*stack_b && (*stack_b)->next
				&& (*stack_b)->value < chunk_min + (chunk_max - chunk_min) / 2)
				rb(stack_b);
		}
		else
			ra(stack_a);
		rotations++;
	}
}

static void	sort_large(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	chunk_size;
	int	chunk;
	int	num_chunks;

	if (size <= 100)
		num_chunks = 5;
	else
		num_chunks = 15;
	chunk_size = size / num_chunks;
	chunk = 0;
	while (chunk < num_chunks)
	{
		push_chunk_to_b(stack_a, stack_b,
			chunk * chunk_size,
			(chunk + 1) * chunk_size - 1);
		chunk++;
	}
	push_chunk_to_b(stack_a, stack_b, chunk * chunk_size, size - 1);
	while (*stack_b)
	{
		rotate_to_top(stack_b, find_max_pos(*stack_b), 'b');
		pa(stack_b, stack_a);
	}
}

void	main_sort_new(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	size;

	size = argc - 1;
	if (check_sorted(*stack_a, *stack_b))
		return ;
	if (size <= 5)
		sort_small(stack_a, stack_b);
	else
		sort_large(stack_a, stack_b, size);
}
