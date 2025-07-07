/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diota.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 20:10:50 by advorace          #+#    #+#             */
/*   Updated: 2025/07/07 20:35:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Get the lengh of n
static double	ft_numlen(double n)
{
	double	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

// Transform n to string representation
char	*ditoa(double n)
{
	double	len1;
	double	len2;
	double	n1;
	double	n2;
	char	*str;

	n1 = n / 1;
	n2 = n % 1;
	len1 = ft_numlen(n1);
	len2 = ft_numlen(n2);
	str = malloc((len1 + len2 + 2) * sizeof(char));
	if (!str)
		return (NULL);
	str[len1 + len2 + 1] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n2)
	{
		str[--len2 + len1 + 1] = (n2 % 10) + '0';
		n2 /= 10;
	}
	str[len1] = '.';
	while (n1)
	{
		str[--len1] = (n1 % 10) + '0';
		n1 /= 10;
	}
	return (str);
}
