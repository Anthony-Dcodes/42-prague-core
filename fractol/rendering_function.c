/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:09:48 by advorace          #+#    #+#             */
/*   Updated: 2026/01/25 14:58:59 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_rainbow(void *param)
{
	t_vars	*vars;
	int		x;
	int		y;
	int		band;
	int		band_lenght;
	int		color_bands[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

	vars = (t_vars *)param;
	band_lenght = vars->win_height / 6;
	x = 0;
	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		band = (y / band_lenght + vars->color_shift) % 6;
		if (band > 5)
			band = 5;
		while (x < vars->win_width)
		{
			my_mlx_pixel_put(&vars->img, x, y, color_bands[band]);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	++vars->frame;
	if (vars->frame % 100 == 0)
		++vars->color_shift;
	return (0);
}

int	render_circle(void *param)
{
	t_vars	*vars;
	double	x1;
	double	y1;
	double	distance;

	vars = (t_vars *)param;
	y1 = 0;
	while (y1 < vars->win_height)
	{
		x1 = 0;
		while (x1 < vars->win_width)
		{
			distance = euclidian_distance(x1, vars->circle_x, y1, vars->circle_y);
			if (distance <= vars->circle_size)
				my_mlx_pixel_put(&vars->img, x1, y1, RED);
			else
				my_mlx_pixel_put(&vars->img, x1, y1, GREEN);
			++x1;
		}
		++y1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

int	render_fractal(void *param)
{
	t_vars	*vars;
	int		x1;
	int		y1;
	double	x_complex;
	double	y_complex;

	vars = (t_vars *)param;
	y1 = 0;
	while (y1 < vars->win_height)
	{
		x1 = 0;
		while (x1 < vars->win_width)
		{
			x_complex = x_coordinate_to_complex_plane(x1, MANDEL_X_MIN, MANDEL_X_MAX, vars->win_width);
			y_complex = y_coordinate_to_complex_plane(y1, MANDEL_Y_MIN, MANDEL_Y_MIN, vars->win_height);
			if (MAX_FRACTAL_ITER == fractal_equation(x_complex, y_complex))
				my_mlx_pixel_put(&vars->img, x1, y1, RED);
			else
				my_mlx_pixel_put(&vars->img, x1, y1, GREEN);
			++x1;
		}
		++y1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
