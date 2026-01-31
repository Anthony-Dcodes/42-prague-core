/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:00:05 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:19:10 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_screen(t_vars *vars, int keycode)
{
	long double	step_x;
	long double	step_y;

	step_x = (vars->x_max - vars->x_min) * 0.05;
	step_y = (vars->y_max - vars->y_min) * 0.05;
	if (keycode == KEY_LEFT)
	{
		vars->x_min -= step_x;
		vars->x_max -= step_x;
	}
	else if (keycode == KEY_RIGHT)
	{
		vars->x_min += step_x;
		vars->x_max += step_x;
	}
	else if (keycode == KEY_UP)
	{
		vars->y_min += step_y;
		vars->y_max += step_y;
	}
	else if (keycode == KEY_DOWN)
	{
		vars->y_min -= step_y;
		vars->y_max -= step_y;
	}
}

int	handle_window_close(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	clean_up(vars, EXIT_SUCCESS);
	return (0);
}

int	key_press_hook(int keycode, void	*param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	if (keycode == KEY_ESC)
		clean_up(vars, EXIT_SUCCESS);
	else if (keycode == KEY_LEFT
		|| keycode == KEY_UP
		|| keycode == KEY_DOWN
		|| keycode == KEY_RIGHT)
		move_screen(vars, keycode);
	return (0);
}
