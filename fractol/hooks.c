/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 19:00:05 by advorace          #+#    #+#             */
/*   Updated: 2026/01/16 20:59:33 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window_red_cross(void *param)
{
	t_vars	*vars;
	vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int close_window_esc(int keycode, void	*param)
{
	t_vars	*vars;
	vars = (t_vars *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	key_hook(int key_code)
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
