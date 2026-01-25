/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:53:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/25 15:07:24 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	euclidian_distance(double x1, double x2, double y1, double y2)
{
	double	distance;

	distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return (distance);
}

double	x_coordinate_to_complex_plane(int x, float x_min, float x_max, int width)
{
	double	x_complex;

	x_complex = x_min + x * ((x_max - x_min) / width);
	return (x_complex);
}

double	y_coordinate_to_complex_plane(int y, float y_min, float y_max, int height)
{
	double	y_complex;

	y_complex = y_max - y * ((y_max - y_min) / height);
	return (y_complex);
}
int	fractal_equation(double x, double y)
{
	int	iter;
	double	a;
	double	b;
	double	new_a;
	double	new_b;

	iter = 0;
	a = 0.0;
	b = 0.0;
	while (iter < MAX_FRACTAL_ITER)
	{
		new_a = a*a - b*b + x;
		new_b = 2*a*b + y;
		a = new_a;
		b = new_b;
		if (a*a + b*b > 4)
			break;
		++iter;
	}
	return (iter);
}


