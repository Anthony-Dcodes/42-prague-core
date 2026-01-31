/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_iterations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:00:59 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:05:38 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_burningship(double x, double y, t_fractal *fract)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = 0.0;
	b = 0.0;
	while (iter < MAX_FRACTAL_ITER)
	{
		a = fabs(a);
		b = fabs(b);
		fract->a = a * a - b * b + x;
		fract->b = 2 * a * b + y;
		a = fract->a;
		b = fract->b;
		if (a * a + b * b > 4)
			break ;
		++iter;
	}
	fract->iter = iter;
	return ;
}

void	compute_mandelbrot(double x, double y, t_fractal *fract)
{
	int		iter;
	double	a;
	double	b;

	iter = 0;
	a = 0.0;
	b = 0.0;
	while (iter < MAX_FRACTAL_ITER)
	{
		fract->a = a * a - b * b + x;
		fract->b = 2 * a * b + y;
		a = fract->a;
		b = fract->b;
		if (a * a + b * b > 4)
			break ;
		++iter;
	}
	fract->iter = iter;
	return ;
}

void	compute_julia(double x, double y, t_fractal *fract,
					t_vars *vars)
{
	int		iter;
	double	a;
	double	b;
	double	new_a;
	double	new_b;

	iter = 0;
	a = x;
	b = y;
	while (iter < MAX_FRACTAL_ITER)
	{
		new_a = a * a - b * b + vars->c_real;
		new_b = 2 * a * b + vars->c_imag;
		a = new_a;
		b = new_b;
		if (a * a + b * b > 4)
			break ;
		++iter;
	}
	fract->a = a;
	fract->b = b;
	fract->iter = iter;
	return ;
}

void	compute_last_z_magnitude(t_fractal *fract)
{
	double	a;
	double	b;

	a = fract->a;
	b = fract->b;
	fract->last_z_magnitude = sqrt(a * a + b * b);
}

void	smooth_iter_count(t_fractal *fract)
{
	int		iter;
	double	last_z_magnitude;

	iter = fract->iter;
	last_z_magnitude = fract->last_z_magnitude;
	fract->smooth_iter_count = iter + 1
		- (log(log(fabs(last_z_magnitude))) / log(2));
}
