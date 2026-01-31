/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:53:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 15:36:14 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	x_coordinate_to_complex_plane(int x, long double x_min,
		long double x_max, int width)
{
	double	x_complex;

	x_complex = x_min + x * ((x_max - x_min) / width);
	return (x_complex);
}

double	y_coordinate_to_complex_plane(int y, long double y_min,
		long double y_max, int height)
{
	double	y_complex;

	y_complex = y_max - y * ((y_max - y_min) / height);
	return (y_complex);
}
