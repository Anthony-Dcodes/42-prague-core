/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:38:47 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 15:11:30 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_at(int x, int y, t_vars *vars, double zoom)
{
	double	cx;
	double	cy;

	cx = x_coordinate_to_complex_plane(x, vars->x_min,
			vars->x_max, vars->win_width);
	cy = y_coordinate_to_complex_plane(y, vars->y_min,
			vars->y_max, vars->win_height);
	vars->x_min = cx + (vars->x_min - cx) * zoom;
	vars->x_max = cx + (vars->x_max - cx) * zoom;
	vars->y_min = cy + (vars->y_min - cy) * zoom;
	vars->y_max = cy + (vars->y_max - cy) * zoom;
}

int	mouse_zoom_hook(int button, int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (button == ON_MOUSEDOWN)
		zoom_at(x, y, vars, ZOOM_FACTOR);
	else if (button == ON_MOUSEUP)
		zoom_at(x, y, vars, 1.0 / ZOOM_FACTOR);
	return (0);
}
