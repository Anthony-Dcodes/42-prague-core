/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:00:05 by advorace          #+#    #+#             */
/*   Updated: 2026/01/27 21:56:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

int	key_hook(int key_code, void *param)
{
	ft_printf("Pressed key code: %d\n", key_code);
	return (0);
}

int	mouse_possition_hook(int x, int y, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	ft_printf("Mouse is at: (%d, %d)\n", x, y);
	return (0);
}

int	move_circle_hook(int key_code, void *param)
{
	t_vars	*vars;

	vars = (t_vars *)param;
	ft_printf("Key pressed: %d\n", key_code);
	if (key_code == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (key_code == KEY_W)
		vars->circle_y -= 10;
	else if (key_code == KEY_A)
		vars->circle_x -= 10;
	else if (key_code == KEY_S)
		vars->circle_y += 10;
	else if (key_code == KEY_D)
		vars->circle_x += 10;
	return (0);
}
