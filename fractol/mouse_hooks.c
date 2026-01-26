/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:38:47 by advorace          #+#    #+#             */
/*   Updated: 2026/01/26 23:05:02 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	zoom_in(int x, int y, t_vars *vars)
{
	vars->x_min *= 0.95;
	vars->x_max *= 0.95;
	vars->y_min *= 0.95;
	vars->y_max *= 0.95;
}

void	zoom_out(int x, int y, t_vars *vars)
{
	vars->x_min /= 0.95;
	vars->x_max /= 0.95;
	vars->y_min /= 0.95;
	vars->y_max /= 0.95;
}

int	mouse_zoom_hook(int button, int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (button == ON_MOUSEDOWN)
		zoom_in(x, y, vars);
	else if (button == ON_MOUSEUP)
		zoom_out(x, y, vars);
	ft_printf("button press on mouse zoom hook: %d\n", button);
	return (0);
}
