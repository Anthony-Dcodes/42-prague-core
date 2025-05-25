/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 09:24:45 by advorace          #+#    #+#             */
/*   Updated: 2025/05/25 10:18:20 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	test_chars[] = {'A', 'z', 'M', '9', '*', ' ', '\n', 'g', '1', '0'};
	int	num_tests = sizeof(test_chars) / sizeof(test_chars[0]);
	int	i = 0;

	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isalpha('%c') = %d\n", c, ft_isalpha(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isdigit('%c') = %d\n", c, ft_isdigit(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isalnum('%c') = %d\n", c, ft_isalnum(c));
		i++;
	}
	printf("\n");
	i = 0;
	while (i < num_tests)
	{
		char	c = test_chars[i];
		printf("ft_isascii('%c') = %d\n", c, ft_isascii(c));
		i++;
	}
	return (0);

}
