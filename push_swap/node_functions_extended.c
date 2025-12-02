/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions_extended.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:56:33 by advorace          #+#    #+#             */
/*   Updated: 2025/12/02 22:00:13 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = (lst)->next;
		free(lst);
		lst = tmp;
	}
}

int	stack_len(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		++i;
	}
	return (i);
}

int	find_first_index_of_range(t_stack *stack, int min, int max)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = stack;
	while (temp)
	{
		if (temp->value >= min
			&& temp->value <= max)
		{
			return (index);
		}
		temp = temp->next;
		++index;
	}
	return (-1);
}

int	find_last_index_of_range(t_stack *stack, int min, int max)
{
	t_stack	*temp;
	int		index;
	int		i;

	index = -1;
	i = 0;
	temp = stack;
	while (temp)
	{
		if (temp->value >= min
			&& temp->value <= max)
		{
			index = i;
		}
		temp = temp->next;
		++i;
	}
	return (index);
}

// Determines rotation direction
// 1 = ra
// 2 == rra
int	determine_rotations(t_stack *stack, int min, int max)
{
	int		first_index;
	int		last_index;
	int		len;

	len = stack_len(stack);
	first_index = find_first_index_of_range(stack, min, max);
	last_index = find_last_index_of_range(stack, min, max);
	if (first_index < (len - last_index))
		return (1);
	else
		return (2);
}
