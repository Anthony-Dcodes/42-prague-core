/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:38:47 by advorace          #+#    #+#             */
/*   Updated: 2026/01/28 19:10:36 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_vars *vars)
{
	double	cx;
	double	cy;

	cx = x_coordinate_to_complex_plane(x, vars->x_min,
			vars->x_max, vars->win_width);
	cy = y_coordinate_to_complex_plane(y, vars->y_min,
			vars->y_max, vars->win_height);
	vars->x_min = cx + (vars->x_min - cx) * SCALING_FACTOR;
	vars->x_max = cx + (vars->x_max - cx) * SCALING_FACTOR;
	vars->y_min = cy + (vars->y_min - cy) * SCALING_FACTOR;
	vars->y_max = cy + (vars->y_max - cy) * SCALING_FACTOR;
}

void	zoom_out(int x, int y, t_vars *vars)
{
	double	cx;
	double	cy;

	cx = x_coordinate_to_complex_plane(x, vars->x_min,
			vars->x_max, vars->win_width);
	cy = y_coordinate_to_complex_plane(y, vars->y_min,
			vars->y_max, vars->win_height);
	vars->x_min = cx + (vars->x_min - cx) / SCALING_FACTOR;
	vars->x_max = cx + (vars->x_max - cx) / SCALING_FACTOR;
	vars->y_min = cy + (vars->y_min - cy) / SCALING_FACTOR;
	vars->y_max = cy + (vars->y_max - cy) / SCALING_FACTOR;
}

int	mouse_zoom_hook(int button, int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (button == ON_MOUSEDOWN)
	{
		zoom_in(x, y, vars);
		vars->max_fractal_iter += 1;
	}
	else if (button == ON_MOUSEUP)
	{
		zoom_out(x, y, vars);
		if (vars->max_fractal_iter > 50)
			vars->max_fractal_iter -=1;
	}
	ft_printf("button press on mouse zoom hook: %d\n", button);
	return (0);
}
