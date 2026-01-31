/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_mapping.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:53:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:10:03 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map_x_to_complex_plane(int x, long double x_min,
		long double x_max, int width)
{
	double	x_complex;

	x_complex = x_min + x * ((x_max - x_min) / width);
	return (x_complex);
}

double	map_y_to_complex_plane(int y, long double y_min,
		long double y_max, int height)
{
	double	y_complex;

	y_complex = y_max - y * ((y_max - y_min) / height);
	return (y_complex);
}
