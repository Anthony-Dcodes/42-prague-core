/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:00:05 by advorace          #+#    #+#             */
/*   Updated: 2026/01/30 23:56:17 by advorace         ###   ########.fr       */
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
		vars->y_min -= step_y;
		vars->y_max -= step_y;
	}
	else if (keycode == KEY_DOWN)
	{
		vars->y_min += step_y;
		vars->y_max += step_y;
	}
}

int	close_window_red_cross(void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	clean_up(vars, EXIT_SUCCESS);
	return (0);
}

int	close_window_esc(int keycode, void	*param)
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

// int	mouse_possition_hook(int x, int y, void *param)
// {
// 	t_vars	*vars;

// 	vars = (t_vars *)param;
// 	ft_printf("Mouse is at: (%d, %d)\n", x, y);
// 	return (0);
// }

// int	move_circle_hook(int key_code, void *param)
// {
// 	t_vars	*vars;

// 	vars = (t_vars *)param;
// 	ft_printf("Key pressed: %d\n", key_code);
// 	if (key_code == KEY_ESC)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(0);
// 	}
// 	if (key_code == KEY_W)
// 		vars->circle_y -= 10;
// 	else if (key_code == KEY_A)
// 		vars->circle_x -= 10;
// 	else if (key_code == KEY_S)
// 		vars->circle_y += 10;
// 	else if (key_code == KEY_D)
// 		vars->circle_x += 10;
// 	return (0);
// }
