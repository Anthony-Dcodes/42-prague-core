/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:39:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/17 13:02:03 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win_width = 1920;
	vars.win_height = 1080;
	vars.color_shift = 0;
	vars.frame = 0;
	vars.win = mlx_new_window(vars.mlx, vars.win_width, vars.win_height, "Hellow world!");
	vars.img.img = mlx_new_image(vars.mlx, vars.win_width, vars.win_height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	my_mlx_square_put(&vars.img, 5, 5, create_trgb(120, 120, 11, 99), 100);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, ON_DESTROY, 0, close_window_red_cross, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 0, close_window_esc, &vars);
	mlx_key_hook(vars.win, close_window_esc, &vars);
	mlx_hook(vars.win, ON_KEYDOWN, 1L << 0, close_window_esc, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, ON_MOUSEMOVE, 0, mouse_possition_hook, &vars);
	mlx_loop_hook(vars.mlx, render_rainbow, &vars);
	mlx_loop(vars.mlx);

}
