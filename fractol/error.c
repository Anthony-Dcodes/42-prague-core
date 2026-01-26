/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:10:07 by advorace          #+#    #+#             */
/*   Updated: 2026/01/26 21:18:02 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage_and_exit()
{
	ft_putstr_fd("Error: Wrong usage!\n", 2);
	ft_putstr_fd("Usage:\n", 2);
	ft_putstr_fd("  ./fractol m\n", 2);
	ft_putstr_fd("  ./fractol j <real> <imag>\n", 2);
	ft_putstr_fd("Hint: Julia values in range [-1.5, 1.5] look best.\n", 2);
	exit(EXIT_FAILURE);
}
