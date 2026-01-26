/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:53:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/26 19:36:28 by advorace         ###   ########.fr       */
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
int	fractal_equation(double x, double y, t_fractal *fract)
{
	int	iter;
	double	a;
	double	b;

	iter = 0;
	a = 0.0;
	b = 0.0;
	while (iter < MAX_FRACTAL_ITER)
	{
		fract->a = a*a - b*b + x;
		fract->b = 2*a*b + y;
		a = fract->a;
		b = fract->b;
		if (a*a + b*b > 4)
			break;
		++iter;
	}
	fract->iter = iter;
	return (iter);
}

void last_z_magnitude(t_fractal *fract)
{
	double	a;
	double	b;

	a = fract->a;
	b = fract->b;
	fract->last_z_magnitude = sqrt(a*a + b*b);
}

void smooth_iter_count(t_fractal *fract)
{
	int		iter;
	double	last_z_magnitude;

	iter = fract->iter;
	last_z_magnitude = fract->last_z_magnitude;
	fract->smooth_iter_count = iter + 1 - (log(log(fabs(last_z_magnitude))) / log(2));
}

void	compute_polynomial_pallete(t_fractal *fract)
{
	double	t;
	double	r;
	double	g;
	double	b;

	last_z_magnitude(fract);
	smooth_iter_count(fract);
	if (fract->iter == MAX_FRACTAL_ITER)
	{
		fract->final_color = BLACK;
		return;
	}
	t = fract->smooth_iter_count / MAX_FRACTAL_ITER;
	r = (int)(255 * (9*(1 - t)*pow(t, 3)));
	g = (int)(255 * (15*pow(1 - t, 2)*pow(t, 2)));
	b = (int)(255 * (8.5*pow(1 - t, 3) *t));
	fract->final_color = create_trgb(0, r, g, b);
 }


