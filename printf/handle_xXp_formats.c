/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xXp_formats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:18:12 by advorace          #+#    #+#             */
/*   Updated: 2025/07/10 21:39:32 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_xXp_formats(char format_specifier, va_list args)
{
	int	x_num;
	int	X_num;
	char *X_str;
	int	i;

	if (format_specifier == 'x')
	{
		x_num = va_arg(args, int);
		return (common_print(int_to_hex(x_num)));
	}
	else if (format_specifier == 'X')
	{
		i = 0;
		X_num = va_arg(args, int);
		X_str = int_to_hex(X_num);
		while (X_str[i])
		{
			X_str[i] = ft_toupper(X_str[i]);
			++i;
		}
		return (common_print(X_str));
	}
	return (-1);
}
