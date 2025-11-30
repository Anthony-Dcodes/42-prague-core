/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 12:51:16 by advorace          #+#    #+#             */
/*   Updated: 2025/11/30 12:51:29 by advorace         ###   ########.fr       */
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
