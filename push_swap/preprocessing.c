/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 12:25:04 by advorace          #+#    #+#             */
/*   Updated: 2025/11/30 12:51:41 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	populate_array(int arg_count, int *array, t_stack **stack_a)
{
	int		i;
	t_stack	*new_node;

	i = 0;
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
	return (1);
}

static void	index_array(int arg_count, t_stack **stack_a, int *array)
{
	t_stack	*temp;
	int		i;

	temp = *stack_a;
	while (temp)
	{
		i = 0;
		while (i < arg_count)
		{
			if (temp->value == array[i])
			{
				temp->value = i;
				break ;
			}
			++i;
		}
		temp = temp->next;
	}
}

int	init_stack_a(t_stack **stack_a, int argc, char **argv)
{
	int		*array;
	int		arg_count;

	arg_count = argc - 1;
	array = malloc(arg_count * sizeof(int));
	if (!array)
		return (0);
	if (!create_safe_array(argc, argv, array))
	{
		free(array);
		return (0);
	}
	if (!populate_array(arg_count, array, stack_a))
		return (0);
	sort_array(arg_count, array);
	if (!duplicates_check(arg_count, array))
	{
		free(array);
		return (0);
	}
	index_array(arg_count, stack_a, array);
	free(array);
	return (1);
}
