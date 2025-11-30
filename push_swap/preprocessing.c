/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:25:04 by advorace          #+#    #+#             */
/*   Updated: 2025/11/30 11:52:46 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_array(int n_elements, int array[])
{
	int	i;
	int	sorted;
	int	temp;

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

int	duplicates_check(int argc, int *array)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (array[i - 1] == array[i])
			return (0);
		++i;
	}
	return (1);
}

int	create_safe_array(int argc, char **argv, int *array)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &value))
			return (0);
		array[i - 1] = value;
		++i;
	}
	return (1);
}

static int	validate_int_check_sign(const char *nptr, int *sign, int *i)
{
	if (!nptr || nptr[0] == '\0')
		return (0);
	if (nptr[*i] == '-' || nptr[*i] == '+')
	{
		if (nptr[*i] == '-')
			*sign = -1;
		(*i)++;
		if (nptr[*i] == '\0')
			return (0);
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
	if (!validate_int_check_sign(nptr, &sign, &i))
		return (0);
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
	t_stack *new_node;
	t_stack *temp;
	int	*array;
	int arg_count;

	i = 0;
	arg_count = argc - 1;
	array = malloc(arg_count * sizeof(int));
	if (!array)
		return (0);
	if (!create_safe_array(argc, argv, array))
	{
		free(array);
		return (0);
	}
	while (i < arg_count)
	{
		new_node = stack_new(array[i]);
		if (!new_node)
			{
				free(array);
				return (0);
			}
		stack_add_back(stack_a, new_node);
		++i;
	}
	sort_array(arg_count, array);
	if (!duplicates_check(arg_count, array))
		{
			free(array);
			return (0);
		}
	temp = *stack_a;
	while (temp)
	{
		i = 0;
		while (i < arg_count)
		{
			if (temp->value == array[i])
				{
					temp->value = i;
					break;
				}
			++i;
		}
		temp = temp->next;
	}
	free(array);
	return (1);
}
