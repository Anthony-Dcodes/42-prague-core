/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_fractal_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 22:00:59 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 15:44:05 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	in_burningship_set(double x, double y, t_fractal *fract)
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

void	in_mandelbrot_set(double x, double y, t_fractal *fract)
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

void	in_julia_set(double x, double y, t_fractal *fract,
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

void	last_z_magnitude(t_fractal *fract)
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

void	compute_polynomial_pallete(t_fractal *fract, t_vars *vars)
{
	long double	t;
	long double	r;
	long double	g;
	long double	b;
	t_vars		*new;

	new = (t_vars *)vars;
	last_z_magnitude(fract);
	smooth_iter_count(fract);
	if (fract->iter == MAX_FRACTAL_ITER)
	{
		fract->final_color = BLACK;
		return ;
	}
	t = fract->smooth_iter_count / MAX_FRACTAL_ITER;
	t = fmod(t + fmod(vars->frame * 0.01, 1.0), 1.0);
	r = (int)(255 * (15 * (1 - t) * pow(t, 2)));
	g = (int)(255 * (8 * pow(1 - t, 2) * pow(t, 2)));
	b = (int)(255 * (3 * pow(1 - t, 3) * t));
	fract->final_color = create_trgb(0, r, g, b);
}
