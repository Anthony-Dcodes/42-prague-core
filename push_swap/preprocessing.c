/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:25:04 by advorace          #+#    #+#             */
/*   Updated: 2025/09/14 12:55:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_array(int n_elements, int array[])
{
	int i;
	int sorted;
	int temp;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 1;
		while (i < n_elements)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				sorted = 0;
			}
			++i;
		}
	}
	return (1);
}

int	duplicates_check(int argc, char **argv)
{
	int	array[argc - 1];
	int	i;
	int value;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &value))
			return (0);
		array[i - 1] = value;
		++i;
	}
	sort_array(argc - 1, array);
	i = 1;
	while (i < argc - 1)
	{
		if (array[i - 1] == array[i])
			return (0);
		++i;
	}
	return (1);

}

// Validate that input
// Every value has to be valid int
int	ft_atoi_safe(const char *nptr, int *out)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign = -1;
		if (nptr[i] == '\0')
			return (0);
	}
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (0);
		if (sign == 1 && result > (INT_MAX - (nptr[i] - '0')) / 10)
			return (0);
		if (sign == -1 && - result < (INT_MIN + (nptr[i] - '0')) / 10)
			return (0);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	*out = (int)(sign * result);
	return (1);
}

int	init_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int	i;
	int	value;
	t_stack *new_node;

	i = 1;
	if (!duplicates_check(argc, argv))
		return (0);
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &value))
			return (0);
		new_node = stack_new(value);
		if (!new_node)
			return (0);
		stack_add_back(stack_a, new_node);
		++i;
	}
	return (1);
}
